#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

// 传入一个表达式字符串求解表达式字符串计算的结果, 其中包含+-(), 其中-可以作为一元运算符参与计算
// 算法思路: 注意如何处理一元运算符
class Solution {
public:
    int calculate(string str) {
        int index = 0;
        return solution(str, index);
    }
    int solution(string &s, int &index) {
        stack<int> tokens;
        int num = 0;
        char sign = '+';

        for (; index < s.size() + 1; ++index) {
            char c = s[index];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                continue;
            }
            if (c == '(') {
                index++;
                num = solution(s, index);
                continue;
            }
            if (!isdigit(c) && c != ' ') {
                int temp;
                switch (sign) {
                    case '+':
                        tokens.push(num);
                        break;
                    case '-':
                        tokens.push(-num);
                        break;
                    case '*':
                        temp = tokens.top();
                        tokens.pop();
                        tokens.push(temp * num);
                        break;
                    default:
                        temp = tokens.top();
                        tokens.pop();
                        tokens.push(temp / num);
                }
                num = 0;
                sign = c;
            }
            if (c == ')')
                break;
        }
        int result = 0;
        while (!tokens.empty()) {
            result += tokens.top();
            tokens.pop();
        }
        return result;
    }
};