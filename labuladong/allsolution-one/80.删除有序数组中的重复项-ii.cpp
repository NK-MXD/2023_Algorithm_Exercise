/*
 * @Date: 2023-05-23 16:26:18
 * @LastEditTime: 2023-05-23 19:52:20
 * @题目描述: 
 * @思路解法: 就是在快慢指针的基础上加上计数, 统计当前slow指针出现的次数
 * @优化思路: 
 * @关键算法: 
 * @复杂度: O(n)
 * @边界条件: 
 * @静态Debug易错点: 注意quick要比slow快一步比较好写
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int slow, quick;
        slow = 0;
        quick = 1;
        int n = nums.size();
        while(quick < n){
            if(nums[quick] == nums[slow] && count < 2){
                slow++;
                nums[slow] = nums[quick];
                count++;
            }else if(nums[quick] != nums[slow]){
                slow++;
                nums[slow] = nums[quick];
                count = 1;
            }
            quick++;
        }
        return slow + 1;
    }
};
// @lc code=end

