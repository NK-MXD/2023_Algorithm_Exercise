/*
 * @Date: 2023-05-23 20:07:27
 * @LastEditTime: 2023-05-23 20:07:43
 * @题目描述: 
 * @思路解法: 首先想到是先进行排序, 但是会破坏原有的索引, 如果要排序需要记录原有的索引, 然后可以使用一个哈希表
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(map.count(num)) return {map[num], i};
            map[target - num] = i;
        }
        return {};
    }
};
// @lc code=end

