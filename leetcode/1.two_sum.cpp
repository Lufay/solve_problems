/**
 * @file 1.two_sum.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.24
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路1：排序，从两边夹逼target（左边定位，右边左移，若找到target，返回之，否则，左边右移一位，右侧若偏大则左移）
 * 思路2：逐个将元素放入map，并检查是否有能结合为target的对应元素
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res(2);
        unordered_map<int, int> num_pos;
		int size = numbers.size();
		for ( int i=0;i<size;++i ) {
			auto iter = num_pos.find(target-numbers.at(i));
			if ( iter == num_pos.end() )
				num_pos.insert(make_pair(numbers.at(i),i+1));
			else {
				res.at(0) = (*iter).second;
				res.at(1) = i+1;
				return res;
			}
		}
		return res;
    }
};