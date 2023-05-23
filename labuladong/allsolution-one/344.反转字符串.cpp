/*
 * @Date: 2023-05-23 16:26:14
 * @LastEditTime: 2023-05-23 16:38:23
 * @题目描述: 
 * @思路解法: 交换一下前后的元素就行
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0, right = n - 1;
        int i = 0;
        while(i < n / 2){
            swap(s[left], s[right]);
            left++;
            right--;
            i++;
        }
    }
};
// @lc code=end

