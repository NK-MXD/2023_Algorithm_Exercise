#include<iostream>
#include<vector>
using namespace std;


// 每次1-3块, 拿掉最后一块的人获胜
// 算法思路: 递归求解
// 问题: 有问题
// 优化思路: 发现只要为4的倍数先手的那个人就一定会输
class Solution{
public:
    bool canWinNim(int n){
        return n % 4 == 0? false: true;
    }
};