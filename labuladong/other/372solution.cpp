#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// 求解一个超级次方取模, 其中次方是使用数组的形式进行表示的, 取的为1337的模
// 思路: 可以先求解对应的n的低位取模, 然后再依次计算高位取模的值
// 问题: 上述方法会产生溢出sum
// 优化思路: 可以发现该问题可以递归为子问题 a b[1, 2, 3] => a^3 (b[1, 2])10
// 优化思路: 对于求幂也有快速递归公式来进行计算
class Solution{
    int base = 1337;
    long mypower(int a, int b){
        if(b == 0) return 1;
        a = a % base;
        long sum;
        for(int i = 0; i < b; i++){
            sum *= a;
            sum %= base;
        }
        return sum;
    }
    long quickpower(int a, int b){
        if(b == 0) return 1;
        a = a % base;
        if(b % 2 == 0){
            long sub = quickpower(a, b / 2);
            return (sub * sub) % base;
        }
        else{
            return (a * quickpower(a, b - 1)) % base;
        }
    }
public:
    int superPow(int a, vector<int>& b){
        if(b.empty()) return 1;
        int k = b.back();
        b.pop_back();
        long power1 = quickpower(a, k);
        long power2 = quickpower(superPow(a, b), 10);
        return (power1 * power2) % base;
    }
};