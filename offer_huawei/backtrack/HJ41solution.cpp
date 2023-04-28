#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 输入: 
// 砝码的种类个数
// 砝码的不同重量
// 砝码的个数

// 输出: 能称出的不同重量的数量

// 想法: 每一个砝码都有两种选择, 加入集合或者不加入, maybe 0-1背包问题的动态规划算法
// 可以先用回溯算法的思路来做一下
// set<int> weight;
// int w = 0;

// void backtrack(vector<int>& nums, int start){
//     weight.insert(w);
//     for(int i = start; i < nums.size(); i++){
//         if(i > start &&  nums[i] == nums[i - 1]){
//             continue;
//         }
//         w += nums[i];
//         backtrack(nums, i + 1);
//         w -= nums[i];
//     }
// }

// int main() {
//     int cate;
//     int w;
//     vector<int> all;// 所有砝码包含重复
//     vector<int> kinds;
//     cin>>cate;
//     for(int i = 0; i < cate; i++){
//         cin>>w;
//         kinds.push_back(w);
//     }
//     for(int i = 0; i < cate; i++){
//         cin>>w;
//         for(int j = 0; j < w; j++){
//             all.push_back(kinds[i]);
//         }
//     }
//     // 下面进行回溯算法:
//     sort(all.begin(), all.end());
//     backtrack(all, 0);
//     cout<<weight.size();
//     return 0;
// }

// 下面这种为动态规划的思路:

int main() {
    int cate;
    int w;
    int sum = 0;
    vector<int> all;// 所有砝码包含重复
    vector<int> kinds;
    cin>>cate;
    for(int i = 0; i < cate; i++){
        cin>>w;
        kinds.push_back(w);
    }
    for(int i = 0; i < cate; i++){
        cin>>w;
        for(int j = 0; j < w; j++){
            all.push_back(kinds[i]);
        }
        sum += w*kinds[i];
    }
    // 状态: 砝码all, 最大重量sum; dp[i][j]表示前i个砝码, 能否刚好装满j的重量
    // 状态转移: dp[i][j] = dp[i - 1][j] | dp[i][j - all[i - 1]]
    int n = all.size();
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= 0; j--){
            if(j - all[i-1] >= 0){
                dp[j] = dp[j] | dp[j - all[i-1]];
            }
        }
    }
    int k = 0;
    for(int i = 0; i <= sum; i++){
        k += dp[i];
    }
    cout<<k;
    return 0;
}