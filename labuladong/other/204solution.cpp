#include<iostream>
#include<vector>
using namespace std;

// 返回所有小于非负整数n的质数的数量
// 思路: n如果不能被比它小的质数整除, 说明n为质数
// 优化思路: 尝试使用素数筛选法来进行解题, 自底向上
class Solution{
public:
    int countPrimes(int n){
        vector<bool> memo(n, true);
        for(int i = 2; i*i < n; i++){
            if(memo[i]){
                for(int j = i*i; j < n; j += i){
                    memo[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(memo[i]) count++;
        }
        return count;
    }
};