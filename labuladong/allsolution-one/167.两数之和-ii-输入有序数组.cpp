/*
 * @Date: 2023-05-23 16:25:37
 * @LastEditTime: 2023-05-23 19:56:54
 * @题目描述: 
 * @思路解法: 找一个map来存放所有的target-num的值, 找到了就算
 * @优化思路: 还有一种方法是双指针技巧, 空间复杂度更小
 * @关键算法: 
 * @复杂度: O(n), map的存放为O(1)复杂度, 但是具有一定的空间复杂度
 * @边界条件: 
 * @静态Debug易错点: 需要注意下标为index + 1
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     int n = numbers.size();
    //     unordered_map<int, int> map;
    //     for(int i = 0; i < n; i++){
    //         int num = numbers[i];
    //         if(map.count(num)) return {map[num], i + 1};
    //         else{
    //             map[target - num] = i + 1;
    //         }
    //     }
    //     return {};
    // }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        int sum;
        while(left < right){
            sum = numbers[left] + numbers[right];
            if(sum > target){
                right--;
            }else if(sum < target){
                left++;
            }else{
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};
// @lc code=end

