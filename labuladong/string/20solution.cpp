#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// 字符串括号是否有效'('，')'，'{'，'}'，'['，']'
// 算法思路: 最基本的算法思路是使用栈的结构, 左入栈, 右出栈
// 算法容易出错的地方在最后栈要为空
class Solution{
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c: s){
            if(c == '(' || c == '{' || c == '['){
                stk.push(c);
            }else{
                if(c == ')'){
                    if(!stk.empty() && stk.top() == '('){
                        stk.pop();
                    }else{
                        return false;
                    }
                }else if(c == '}'){
                    if(!stk.empty() && stk.top() == '{'){
                        stk.pop();
                    }else{
                        return false;
                    }
                }else if(c == ']'){
                    if(!stk.empty() && stk.top() == '['){
                        stk.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return stk.empty()? true: false;
    }
};