#include<iostream>
#include<vector>
using namespace std;

// 求解阶乘后有多少零
// 思路: 实际上是计算其中阶乘项当中有多少个5, 其中5的个数可以通过除以5来进行计算
class Solution{
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n != 0){
            res += n / 5;
            n = n / 5;
        }
        return res;
    }
};