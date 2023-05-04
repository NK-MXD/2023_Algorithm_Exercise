#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// 求解灯泡亮着的个数
// 算法思路: 只有平方次数的灯才是奇数次被按下
class Solution{
public:
    int bulbSwitch(int n){
        return sqrt(n);;
    }
};