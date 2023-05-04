#include<iostream>
#include<vector>
using namespace std;

// 判断是否为2的倍数, 即二进制表达中, 只有一位为1
class Solution{
public:
    bool isPowerOfTwo(int n) {
        return (n & (n - 1) == 0? true: false);
    }
};