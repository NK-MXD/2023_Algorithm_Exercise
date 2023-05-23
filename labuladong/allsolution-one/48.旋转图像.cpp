/*
 * @Date: 2023-05-23 22:43:35
 * @LastEditTime: 2023-05-23 22:52:38
 * @题目描述: 
 * @思路解法: 
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 注意auto里面带有&符号表示对当前元素进行修改, 否则为对临时变量进行修改
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先沿对角线反转二维矩阵
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 然后反转二维矩阵的每一行
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};
// @lc code=end

