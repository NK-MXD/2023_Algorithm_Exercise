#include<iostream>
#include<vector>
using namespace std;

// 获取数转二进制数的1的个数
class Solution{
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n != 0){
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};