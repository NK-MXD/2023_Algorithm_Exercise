#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

// 字符串的乘法问题, 但是不能使用库函数将字符串转化为整数进行计算
// 算法思想: 模仿手写乘法的思路
// 每次计算时会有一个数组来专门记录计算的结果
// 问题思考: 为什么每次存值不需要考虑进位??
// 这是因为最后计算的是高位, 高位从低位中取出值来进行存放, 至于低位存放的是大于9的数字或者小于9的最后总会合法
class Solution{
public: 
    string multiply(string num1, string num2){
        int n = num1.size(), m = num2.size();
        // 长度最长为 m + n
        vector<int> res(m + n, 0);
        // 翻转一下字符串好算
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        // 下面开始遍历计算
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                // 遍历乘法
                int i1 = num1[i] - '0';
                int i2 = num2[j] - '0';
                // 计算乘法
                int add = i1 * i2;
                // 取出数组存的值
                int old = res[i + j + 1]*10 + res[i + j];
                int n = add + old;
                // 存值
                res[i + j + 1] = n / 10;
                res[i + j] = n % 10;
            }
        }
        // 输出
        reverse(res.begin(), res.end());
        int i = 0;
        while (i < res.size() && res[i] == 0)
            i++;
        string str;
        for(; i < res.size(); i++){
            str.push_back('0' + res[i]);
        }
        return str.size() == 0 ? "0" : str;
    }
};