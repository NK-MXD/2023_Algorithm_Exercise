/*
 * @Date: 2023-05-23 20:12:02
 * @LastEditTime: 2023-05-23 20:52:33
 * @题目描述: 
 * @思路解法: 本题和第1的区别在这题的题目条件是4个数字之和, 类似第一题的思路, 可以使用动态规划的dp数组来存
 * @优化思路: 或者也可以使用递归的思路, 递归基为2sum问题
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: target可能会发生越界
 * @相关题目: 1
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return Nsum(nums, target, 4, 0);
    }
};
// @lc code=end

