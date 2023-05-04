#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 求解所有优先级的表达式的可能的值
// 算法: 分治思想
// 思路: 根据运算符将表达式分为两个字表达式-分, 然后根据子表达式的值进行治
// 优化算法: 使用备忘录优化算法
// 问题: 添加unique标识会报错????? 为什么????
class Solution{
    unordered_map<string, vector<int>> memo;
public:
    vector<int> diffWaysToCompute(string expression){
        if(memo.count(expression)){
            return memo[expression];
        }
        int n = expression.size();
        unordered_set<int> unique;
        vector<int> res;
        for(int i = 0; i < n; i++){
            char ch = expression[i];
            if(ch == '+' || ch == '-' || ch == '*'){
                string str1 = expression.substr(0, i);
                string str2 = expression.substr(i + 1, n - i + 1);
                vector<int> left = diffWaysToCompute(str1);
                vector<int> right = diffWaysToCompute(str2);
                int result = 0;
                for(int i = 0; i < left.size(); i++){
                    for(int j = 0; j < right.size(); j++){
                        if(ch == '+')
                            result = left[i] + right[j];
                        else if(ch == '-')
                            result = left[i] - right[j];
                        else{
                            result = left[i] * right[j];
                        }
                        // if(!unique.count(result)){
                            res.push_back(result);
                            // unique.insert(result);
                        // }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(atoi(expression.c_str()));
        }
        memo[expression] = res;
        return res;
    }
};