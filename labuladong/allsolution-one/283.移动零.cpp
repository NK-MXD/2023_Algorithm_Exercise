/*
 * @Date: 2023-05-23 16:26:05
 * @LastEditTime: 2023-05-23 16:39:30
 * @题目描述: 
 * @思路解法: 将所有的0移动为数组的末尾, 使用快慢指针, 最后所有的元素全抹零
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow, quick;
        slow = quick = 0;
        while(quick < n){
            if(nums[quick] != 0){
                nums[slow++] = nums[quick];
            }
            quick++;
        }
        for(;slow < n; slow++){
            nums[slow] = 0;
        }
    }
};
// @lc code=end

