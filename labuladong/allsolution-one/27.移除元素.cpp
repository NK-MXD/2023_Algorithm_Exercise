/*
 * @Date: 2023-05-23 16:26:00
 * @LastEditTime: 2023-05-23 16:31:13
 * @题目描述: 
 * @思路解法: 可以将数值为val的元素不管它
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, right = 0;
        int n = nums.size();
        while(right < n){
            if(nums[right] != val){
                nums[slow++] = nums[right];
            }
            right++;
        }
        return slow;
    }
};
// @lc code=end

