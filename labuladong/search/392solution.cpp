#include<iostream>
#include<vector>
using namespace std;

// 给定字符串s和t, 判断s是否为t的子序列
// 算法思路: 一次遍历
// 优化算法: 上述的复杂度为O(n), 但是试想一下当t非常长, s非常短的时候, 这样子就不很划算
// 二分思路优化: 暂时放在这里
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;  
        int n = t.size(), m = s.size();
        for(;i < n; i++){
            if(j == m) break;
            if(t[i] == s[j]){
                j++;
                continue;
            }
        }
        return j == m;
    }
};