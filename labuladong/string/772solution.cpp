#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

// 处理字符串表达式的运算, 包含+-*/()
// 算法思路: 首先, 可以将每一个数字运算字符分出来作为一个单独的token
// 然后使用栈进行计算, 这里的计算逻辑为: 
// 1. 分为两个栈: 操作数栈和操作码栈
// 2. 如果是操作数直接进入操作数栈;
// 3. 如果遇到左括号, 直接入栈;
// 4. 如果是操作码, 如果操作码栈为空直接入栈; 
//      4.1 如果不为空, 弹出栈顶操作码, 和当前操作码比较优先级, 如果低于, 则将当前操作码压栈;
//      4.2 如果不低于, 从操作数栈中弹出两个操作数, 用弹出的操作码进行计算, 计算结果入操作数栈;
//      4.3 继续弹操作码栈,和当前操作码比较,重复前面的处理方法, 直到遇见低的操作码或操作码栈空,当前操作码入操作码栈.
// 5. 如果遇到右括号, 直接弹出栈顶操作码和两个操作数, 运算, 结果记录压入操作数栈, 继续弹操作码和操作数, 直到遇到左括号
class Solution {
    // 字符串转化为tokens
    vector<int> splitStr(string s){
        vector<int> res;
        int n = s.size();
        int num = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                flag = true;
                num = num*10 + (s[i] - '0');
                if(i == n - 1)
                    res.push_back(num);
            }else if(!isdigit(s[i]) && s[i] != ' ') {
                if(flag) res.push_back(num);
                res.push_back(s[i]);
                num = 0;
                flag = false;
            }
        }
        return res;
    }
    // 判断运算符的优先级2比1
    bool bigequal(int op1, int op2){
        if(op2 == '(') return false;
        if(op1 == '+' || op1 == '-'){
            return true;
        }else if(op1 == '*' || op1 == '/'){
            if(op2 == '*' || op2 == '/' || op2 == '(')
                return true;
        }else{
            return false;
        }
        return false;
    }
    // 用操作码进行计算
    int cal(int op, int i1, int i2){
        if(op == '+'){
            return i1 + i2;
        }else if(op == '-'){
            return i2 - i1;
        }else if(op == '*'){
            return i1 * i2;
        }else{
            return i2 / i1;
        }
    }
public:
    int calculate(string s) {
        // 首先将字符串转化为token, 符号用asicc码表示, 数字用本身的值表示
        vector<int> tokens;
        tokens = splitStr(s);
        // 然后将数字和符号分别压到栈中, 进行计算
        stack<int> nums, operations;
        for(auto i: tokens){
            if(i == '+' || i == '-' || i == '*' || i == '/'){
                if(operations.empty()){
                    operations.push(i);
                    continue;
                }
                // 比较优先级
                int top = operations.top();
                while(!operations.empty() && bigequal(i, top)){
                    int i1 = nums.top();
                    nums.pop();
                    int i2 = nums.top();
                    nums.pop();
                    int res = cal(top, i1, i2);
                    nums.push(res);
                    operations.pop();
                    if(!operations.empty()) top = operations.top();
                }
                operations.push(i);
            }else if(i == '('){
                operations.push(i);
            }else if(i == ')'){
                int top = operations.top();
                while(!operations.empty() && top != '('){
                    int i1 = nums.top();
                    nums.pop();
                    int i2 = nums.top();
                    nums.pop();
                    int res = cal(top, i1, i2);
                    nums.push(res);
                    operations.pop();
                    if(!operations.empty()) top = operations.top();
                }
                operations.pop();
            }else{
                nums.push(i);
            }
        }
        // 在计算的最后, 将栈的元素都pop出来
        int top;
        while(!operations.empty()){
            top = operations.top();
            int i1 = nums.top();
            nums.pop();
            int i2 = nums.top();
            nums.pop();
            int res = cal(top, i1, i2);
            nums.push(res);
            operations.pop();
            if(!operations.empty()) top = operations.top();
        }
        return nums.top();
    }
};