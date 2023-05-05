#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 输入一个升序的数组, 判断能否被分割为若干长度至少为3的子序列, 每个子序列都是一个连续递增序列
// 算法思路: 每次有一个序列纳入新的值, 判断是否为递增子序列
// 问题: 子序列可以是不连续的
// 优化思路: 每次子序列可以分为两个部分, 承接上次的子序列或者以自己为开头新开一个子序列
// 拓展: 如果要记录具体的子序列可以从need数组下手
class Solution{
public:
    bool isPossible(vector<int>& nums){
        unordered_map<int, int> need, freq;
        //其中freq代表每次有多少个
        for(auto i: nums){
            freq[i]++;
        }
        for(auto i: nums){
            if(freq[i] == 0){
                continue;
            }
            // 首先看能够承接上一次的子序列
            if(need.count(i) && need[i] > 0){
                need[i]--;
                freq[i]--;
                need[i+1]++;
            }
            // 如果不行的话自成一个序列
            else if(freq[i] > 0 && freq[i+1] > 0 && freq[i + 2] > 0){
                need[i + 3]++;
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
            }else{
                return false;
            }
        }
        return true;
    }
};