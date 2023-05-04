#include<iostream>
#include<vector>
#include<random>
using namespace std;

// 按照权重随机选取下标
// 算法: 随机生成随机数, 随机数介于权重之间的就生成对应的数字, 介于权重之间的算法是二分搜索算法
class Solution {
    int sum = 0;
    vector<int> weight;
    default_random_engine gen{random_device{}()};
    int search(vector<int> nums, int target){
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid = left + (right - left)/2;
        while(left < right){
            if(nums[mid] > target){
                right = mid;
            }else if(nums[mid] < target){
                left = mid;
            }else{
                right = mid;
            }
        }
        return left;
    }
public:
    Solution(vector<int>& w) {
        weight = w;
        for(int i = 0; i < w.size(); i++){
            sum += w[i];
            weight[i] = sum;
        }
    }
    
    int pickIndex() {
        int k = gen()%sum;
        int index = search(weight, k);
        return index;
    }
};