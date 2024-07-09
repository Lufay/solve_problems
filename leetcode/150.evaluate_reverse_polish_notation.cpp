/**
 * @file 150.evaluate_reverse_polish_notation.cpp
 * @author life000
 * @brief 
 * @version 0.1
 * @date solved at 2014.06.17
 * 
 * @copyright Copyright (c) 2024
 * 
 * 思路：用栈
 * 注意：负数
 */
 class Solution {
    stack<int> si;
public:
    int toInt(const string &num) { 
        stringstream buf;
        buf << num; 
        int temp = 0;
        buf >> temp;
        return temp;
    }
    bool isNum(const string &str) { 
        char c = str.at(str.length()-1);
        return c >= '0' && c <='9';
    }
    int operate(const string &op) {
        int b = si.top();
        si.pop();
        int a = si.top();
        si.pop();
        switch(op.at(0)){
            case '+':
            return a + b;
            case '-':
            return a - b;
            case '*':
            return a * b;
            case '/':
            return a / b;
        }       
    }

    int evalRPN(vector<string> &tokens) {
        for ( vector<string>::iterator iter=tokens.begin();
            iter != tokens.end(); ++iter) {
            if ( isNum(*iter) ) {
                si.push(toInt(*iter));
            }       
            else    
                si.push(operate(*iter));
        }       
        return si.top();
    }
};
