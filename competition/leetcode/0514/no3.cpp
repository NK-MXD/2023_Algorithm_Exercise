/*
 * @Date: 2023-05-14 11:13:45
 * @LastEditTime: 2023-05-14 11:37:44
 * @题目描述: 从矩阵第一列当中的任意单元格出发, 可以走右上右右下的任意单元格值大于当前单元格值的格子
 * 返回能在矩阵中移动的最大次数
 * @思路解法: 动态规划, 递归基是最右边的格子为0, 递归方程为max(grid[i - 1][j + 1], grid[i][j + 1], grid[i + 1][j + 1]) + 1
 * 从最大的开始遍历, 行无所谓, 关键是列
 * @优化思路:
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: if(grid[i][j] < grid[i - 1][j + 1]) if(grid[i][j] < grid[i][j + 1]) 注意不是else if!!!!!
 * @相关题目: 
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dptable(m, vector<int>(n, 0));
        //其中dp[...][n - 1]为0
        for(int j = n - 2; j >= 0; j--){
            for(int i = 0; i < m; i++){
                if(i - 1 >= 0 && i + 1 < m){
                    if(grid[i][j] < grid[i - 1][j + 1]){
                        dptable[i][j] = max(dptable[i][j], dptable[i - 1][j + 1] + 1);
                    }
                    if(grid[i][j] < grid[i][j + 1]){
                        dptable[i][j] = max(dptable[i][j], dptable[i][j + 1] + 1);
                    }
                    if(grid[i][j] < grid[i + 1][j + 1]){
                        dptable[i][j] = max(dptable[i][j], dptable[i + 1][j + 1] + 1);
                    }
                }else if(i - 1 >= 0){
                    if(grid[i][j] < grid[i - 1][j + 1]){
                        dptable[i][j] = max(dptable[i][j], dptable[i - 1][j + 1] + 1);
                    }
                    if(grid[i][j] < grid[i][j + 1]){
                        dptable[i][j] = max(dptable[i][j], dptable[i][j + 1] + 1);
                    }
                }else if(i + 1 < m){
                    if(grid[i][j] < grid[i][j + 1]){
                        dptable[i][j] = max(dptable[i][j], dptable[i][j + 1] + 1);
                    }
                    if(grid[i][j] < grid[i + 1][j + 1]){
                        dptable[i][j] = max(dptable[i][j], dptable[i + 1][j + 1] + 1);
                    }
                }else{
                    dptable[i][j] = 0;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            if(dptable[i][0] > res){
                res = dptable[i][0];
            }
        }
        return res;
    }
};