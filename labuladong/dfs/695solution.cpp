#include<iostream>
#include<vector>
using namespace std;

// 求解岛屿的最大面积
// 算法: dfs
// 思路: 使用dfs的返回值, 根据返回值选取最大的岛屿
class Solution{
private:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1){
            return;
        }
        if(grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        return dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + 
            dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int res = 0;   
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
    }
};