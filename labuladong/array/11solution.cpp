#include<iostream>
#include<vector>
using namespace std;

// 找到空闲距离最大的数组中的两个值, 说白了就是求解min(height[left], height[right]) * (right - left)的最大值
// 算法思路: 一个优化的算法思路是双指针, 从两边进行缩紧, 一边收缩一边计算值;
// 收缩的方式是从较低的一侧开始的
class Solution{
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int l_max = 0, r_max = 0;
        while(left < right){
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if(l_max < r_max){
                res = max(res, l_max*(right - left));
                left++;
            }else{
                res = max(res, r_max*(right - left));
                right--;
            }
        }
        return res;
    }
};