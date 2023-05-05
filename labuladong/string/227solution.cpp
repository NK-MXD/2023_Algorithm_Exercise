#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

// 处理字符串表达式的运算, 包含+-*/
// 算法思路: 参考772
class Solution {
    vector<bool> opflag;
    // 字符串转化为tokens
    vector<int> splitStr(string s){
        s.erase(remove_if(s.begin(), s.end(),
            [](char c) { return std::isspace(c); }), s.end());
        vector<int> res;
        int n = s.size();
        int num = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                flag = true;
                num = num*10 + (s[i] - '0');
                if(i == n - 1){
                    res.push_back(num);
                    opflag.push_back(false);
                }
            }else if(!isdigit(s[i]) && s[i] != ' ') {
                if(flag){
                    res.push_back(num);
                    opflag.push_back(false);
                }
                res.push_back(s[i]);
                opflag.push_back(true);
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
        for(int k = 0; k < tokens.size(); k++){
            int i = tokens[k];
            bool op = opflag[k];
            if(op && (i == '+' || i == '-' || i == '*' || i == '/')){
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
            }else if(op && i == '('){
                operations.push(i);
            }else if(op && i == ')'){
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