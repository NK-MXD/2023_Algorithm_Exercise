#include<iostream>
#include<vector>
using namespace std;

// 找到缺失的数字: 一种更加巧妙的方法是利用位来进行操作
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long sum = n * (n + 1)/2;
        for(auto i: nums){
            sum -= i;
        }
        return sum;
    }
    int missingNumber2(vector<int>& nums) {
        int n = nums.size();   
        int res = 0;
        for(int i = 0; i < n; i++){
            res ^= i ^ nums[i];
        }
        return res^n;
    }
};