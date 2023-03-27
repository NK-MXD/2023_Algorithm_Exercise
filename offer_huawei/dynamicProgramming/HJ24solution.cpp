#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

// 尝试使用最长递增子序列的思路来解题
// 首先在序列中找到最长递增子序列, 然后根据得到的最大的值, 反推其中最长的递减序列???

// 分治的思想可以吗?
// 以其中任意一个数为最大值, 分别求两段的最长递增子序列

// 写一个最长递增子序列算法:
int getLengthInc(vector<int>& v){
    int length = v.size();
    vector<int> dp(length, 1);
    // 基本的算法思路是使用动态规划的思路计算当前长度的最长递增子序列
    for(int i = 0; i < length; i++){
        for(int j = 0; j < i; j++){
            if(v[j] < v[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    // 返回的值是最后一个变量一定存在时的最长递增子序列
    return dp[length - 1];
}

int main() {
    int N;
    cin>>N;
    vector<int> num(N,0);
    for(int i = 0; i < N; i++){
        cin>>num[i];
    }
    
    int k = 0; 
    int temp = 0;
    for(int index = 1; index < N - 1; index++){
    // 遍历所有的数为最大值, 但是实际情况可能是这种 1 2 3 1 3 2 1, 这样子的话就不是单纯的中间的1左边的最大 + 右边的最大
    // 将vector一分为二
        vector<int> left(index + 1,0), right(N - index,0);
        copy(num.begin(), num.begin() + index + 1, left.begin());
        copy(num.begin() + index, num.end(), right.begin());
        right.reserve(right.size());
        // 分别计算最长递增子序列
        temp = getLengthInc(left) + getLengthInc(right);
        if(temp > k) k = temp;
    }
    // 这种思路计算的结果偏大
    cout<< N - k + 1;
    return 0;
}
