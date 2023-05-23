/*
 * @Date: 2023-05-23 21:45:48
 * @LastEditTime: 2023-05-23 22:02:28
 * @题目描述: 相当于我先求数组中以一个元素为中心的小矩形的和, 再输出得到最后的矩形
 * @思路解法: 求小矩形的和可以使用前缀和的手段来求
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 坐标在获取的时候处理比较简单
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> prefixsum;
    int getSum(int row1, int col1, int row2, int col2){
        return prefixsum[row2 + 1][col2 + 1] - prefixsum[row2 + 1][col1] - 
                prefixsum[row1][col2 + 1] + prefixsum[row1][col1];
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        prefixsum.resize(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefixsum[i + 1][j + 1] = prefixsum[i][j + 1] + prefixsum[i + 1][j] +
                                    mat[i][j] - prefixsum[i][j];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // 左上角的坐标
                int x1 = max(i - k, 0);
                int y1 = max(j - k, 0);
                // 右下角坐标
                int x2 = min(i + k, m - 1);
                int y2 = min(j + k, n - 1);
                res[i][j] = getSum(x1, y1, x2, y2); 
            }
        }
        return res;
    }
};
// @lc code=end

