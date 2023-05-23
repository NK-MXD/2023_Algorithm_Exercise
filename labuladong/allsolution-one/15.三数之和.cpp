/*
 * @Date: 2023-05-23 20:11:59
 * @LastEditTime: 2023-05-23 20:53:35
 * @题目描述: 
 * @思路解法: 参考18中的思路可以得到适用范围更广泛的算法, 也可以参考2sum的实现
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 1, 18
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
    // 设置Nsum函数, n代表有相加sum的数目
    vector<vector<int>> Nsum(vector<int>& nums, long target, int n, int start){
        int length = nums.size();
        vector<vector<int>> res;
        // 递归基
        if(n == 2){
            int left = start, right = length - 1;
            long sum;
            int leftnum, rightnum;
            while(left < right){
                leftnum = nums[left];
                rightnum = nums[right];
                sum = leftnum + rightnum;
                if(sum < target){
                    while(left < right && nums[left] == leftnum) left++;
                }else if(sum > target){
                    while(left < right && nums[right] == rightnum) right--;
                }else{
                    res.push_back({leftnum, rightnum});
                    while(left < right && nums[left] == leftnum) left++;
                    while(left < right && nums[right] == rightnum) right--;
                }
            }
            return res;
        }
        for(int i = start; i < length; i++){
            vector<vector<int>> prevres = Nsum(nums, target - nums[i], n - 1, i + 1);
            if(!prevres.empty()){
                for(vector<int>& r: prevres){
                    r.push_back(nums[i]);
                    res.push_back(r);
                }
            }
            while(i < length - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return Nsum(nums, 0, 3, 0);
    }
};
// @lc code=end

