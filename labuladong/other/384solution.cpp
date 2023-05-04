#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

// 随机洗牌算法: 使得从中选取任一元素的可能性都相等, 也就是说随机产生的排列的个数为n!个数
class Solution {
    vector<int> origin;
    default_random_engine gen{random_device{}()};
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> temp(origin);
        int n = origin.size();
        for(int i = 0; i < n; i++){
            uniform_int_distribution<int> distribution(i, n - 1);
            int r = distribution(gen);
            swap(temp[i], temp[r]);
        }
        return temp;
    }
};