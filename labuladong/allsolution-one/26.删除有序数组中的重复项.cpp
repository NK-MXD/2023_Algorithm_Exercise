/*
 * @Date: 2023-05-23 16:10:09
 * @LastEditTime: 2023-05-23 16:22:12
 * @题目描述: 
 * @思路解法: 本题目的优雅解法是使用快慢指针来进行控制元素不重复
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int slow = 0, fast = 0;
        while(fast < nums.size()){
            if(nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};
// @lc code=end

