/*
 * @Date: 2023-05-23 21:35:18
 * @LastEditTime: 2023-05-23 21:39:03
 * @题目描述: 
 * @思路解法: 同样使用前缀和, 不过两差加一个公共区域
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include<vector>
using namespace std;
// @lc code=start
class NumMatrix {
private:
    vector<vector<int>> prefixsum;  // 存(i, j)为矩阵行列的矩阵和(0...i - 1)(0...j - 1)
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = 0;
        prefixsum.resize(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefixsum[i + 1][j + 1] = prefixsum[i + 1][j] + prefixsum[i][j + 1] + 
                                        matrix[i][j] - prefixsum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixsum[row2 + 1][col2 + 1] - prefixsum[row2 + 1][col1] -
            prefixsum[row1][col2 + 1] + prefixsum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

