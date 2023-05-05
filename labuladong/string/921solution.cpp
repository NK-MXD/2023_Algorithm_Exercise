#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// 最少添加的括号数目使得括号字符串有效
// 相关题目: 第20题
// 算法思路: 无非就是括号数目不匹配, 返回不匹配数目试一试
// 问题: 注意这种情况: "()))(("
// 还是用栈
class Solution{
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int res = 0;
        for(auto c: s){
            if(c == '('){
                stk.push(c);
            }
            else if(c == ')'){
                if(stk.empty()){
                    res++;
                    continue;
                }
                stk.pop();
            }
        }
        return res + stk.size();
    }
};