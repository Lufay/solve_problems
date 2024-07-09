/**
 * @file 146.LRU_cache.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.22
 * 
 * @copyright Copyright (c) 2024
 * 
 * 题意是完全基于时间的，即不考虑访问频次，优先淘汰最近没被访问的元素
 * 思路：同样哈希存储key-value，只不过这里的value是一个链表的结点（迭代器），此链表的头表示最近被访问，反之，尾就是优先淘汰的
 */
 class LRUCache{
	unordered_map<int, list<pair<int,int> >::iterator> cache;   //使用list的迭代器，因为List的增删操作都不影响迭代器，从而可以类似指针指向一个结点
	list<pair<int,int> > kv_queue;		//front is recently access，冗余存储key，是为了能查到cache的对应位置
	const int _capacity;
public:
    LRUCache(int capacity) :_capacity(capacity) {
    }

	int& access(int key) {
		list<pair<int,int> >::iterator iter = cache.at(key);
		int value = (*iter).second;
		kv_queue.erase(iter);
		kv_queue.push_front(make_pair(key,value));
		cache.at(key) = kv_queue.begin();   //小心，由于上面的erase操作，导致iter已经失效，需要重新生成iter
		return kv_queue.front().second;
	}

    int get(int key) {
        if ( cache.find(key) == cache.end() )
			return -1;
		return access(key);
    }
    
    void set(int key, int value) {
		if (cache.find(key) == cache.end()) {	//不存在
			if (cache.size() == _capacity) {	//满了
				cache.erase(kv_queue.back().first);
				kv_queue.pop_back();
			}
			kv_queue.push_front(make_pair(key,value));
			cache.insert( make_pair(key, kv_queue.begin()) );
		}
		else
			access(key) = value;
    }
};

// 若考虑访问频次
// 思路：基于访问频次，相同访问频次下，优先淘汰最早访问的。哈希存储key-value，map存储访问频次到key队列的映射，利用map的有序行，map::begin()即为访问频次最小，队首即为最早访问的那个key，将淘汰。
struct Content {
    int value;
    int hit;
    Content() :value(0), hit(1) {}
    Content(int val) :value(val), hit(1) {}
};

class LRUCache{
    unordered_map<int, Content> cache;
    map<int, deque<int> > hit_queues; //使用deque可以优先淘汰hit值相同的最早访问的元素，如果不做此要求可以用unordered_set
    const int _capacity;
public:
    LRUCache(int capacity) :_capacity(capacity) {
    }   
    int& access(int key) {
        Content &tc = cache.at(key);
        deque<int> &tq = hit_queues.at(tc.hit);
        if ( tq.size() == 1 )
            hit_queues.erase(tc.hit);
        else
            tq.erase(find(tq.begin(), tq.end(), key));
        hit_queues[++tc.hit].push_back(key);
        return tc.value;
    }
    
    int get(int key) {
        if ( cache.find(key) == cache.end() )
            return -1;
        return access(key);
    }
    
    void set(int key, int value) {
        if (cache.find(key) == cache.end()) { //不存在
            if (cache.size() == _capacity) { //满了，先淘汰
                map<int, deque<int> >::iterator small_iter = hit_queues.begin();
                cache.erase((*small_iter).second.front());
                if ((*small_iter).second.size() == 1)
                    hit_queues.erase(small_iter);
                else
                    (*small_iter).second.pop_front();
            }
            cache.insert( pair<int, Content>(key, Content(value)) );
            hit_queues[1].push_back(key);
        }
        else
            access(key) = value;
    }
};