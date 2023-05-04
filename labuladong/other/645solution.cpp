#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 1-n的范围内, 有一个数字重复, 丢失了一个数字, 找到重复与丢失的数字
// 思路: 最简单的思路用后一个减去前一个, 然后观察其中不为0的值
// 问题: 有可能正好缺少最后一个数值
// 优化思路: 将此情形当作index和数字的相互映射
class Solution{
public:
    vector<int> findErrorNums(vector<int>& nums){
        int n = nums.size();
        vector<int> sign(n, 1);//数字是啥不重要
        vector<int> res;
        for(auto n: nums){
            if(sign[n - 1] < 0){
                res.push_back(n);
                continue;
            }
            sign[n - 1] = -1;
        }
        for(int i = 0; i < n; i++){
            if(sign[i] > 0){
                res.push_back(i + 1);
                break;
            }
        }
        return res;
    }
};