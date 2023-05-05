#include<iostream>
#include<vector>
using namespace std;

// 接雨水问题
// 算法思路: 不要纠结于直接求出整个的容器能够装下多少水, 只去思考, 对于一个位置能够装多少水
// 对于一个位置能够装下多少水取决于它两边的最大值的最小值
// 一次遍历, 左边的最大值是很好计算的, 那就动态调整右边的最大值
// 优化算法: 可以直接存一个数组来记录左边最大的和右边最大的, 或者直接使用动态的双指针进行调整
class Solution{
public:
    int trap(vector<int>& height) {
        int left = 0, right = 0;
        // 初始化左右的最大值
        int sum = 0; 
        // 总的雨水
        int n = height.size();
        for(int i = 1; i < n - 1; i++){
            // 更新左边的最大值
            if(height[i - 1] > height[left]) left = i - 1;
            // 动态更新右边的最大值
            if(right <= i){
                right = i + 1;
                for(int j = i + 1; j < n; j++){
                    if(height[j] > height[right]) right = j;
                }
            }
            // 得到雨水值
            int res = min(height[left], height[right]) - height[i];
            if(res > 0)
                sum += res;
        }
        return sum;
    }
    int trap2(vector<int>& height) {
        int n = height.size();
        int l_max = 0, r_max = 0;
        int left = 0, right = n - 1;
        int res = 0;
        while(left < right){
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);
            if(l_max < r_max){
                res += l_max - height[left];
                left++;
            }else{
                res += r_max - height[right];
                right--;
            }
        }
        return res;
    }
};