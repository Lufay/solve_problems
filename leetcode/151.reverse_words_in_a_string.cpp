/**
 * @file 151.reverse_words_in_a_string.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.17
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路1：串翻转+单词翻转
 * 注意：1.空串；2.头尾空格的trim；3.中间连续的空格——转为1个
 */

class Solution {
public:
    void reverse(string &s,int end,int start=0) {   //可以使用std::reverse替代
        while ( start < end )
            swap(s[start++], s[end--]);
    }
        
    void reverseWords(string &s) {
        if ( s.empty() )
            return;
        reverse(s, s.length()-1);
        int word_start = 0,word_end=0;
        for ( int i=0; i<s.length(); i++) {
            if ( s[i] == ' ' ) { 
                if ( word_start < word_end ) {
                    reverse(s, word_end-1, word_start);
                    s[word_end++] = ' ';
                    word_start = word_end;
                }       
            }       
            else {  
                s[word_end++] = s[i]; 
            }       
        }       
        if ( word_start < word_end ) {
            reverse(s, word_end-1, word_start);
        }       
        else    
            if ( word_end > 0 )
                word_end--;
        s.resize(word_end);
    }
};

// solved at 2014.06.20
// 思路2：用str构造istringstream输出
class Solution {
public:
    void reverseWords(string &s) {
        istringstream iss(s);
        string res;
        while(iss >> s)
            res = s + " " + res;
        s = res.substr(0, res.length()-1);  //这里用了一个巧合，对于空串，pop_back和resize是不行的，而substr的第二个参数却支持string::npos表示全串，其值恰好为-1
    }
};