#include<iostream>
#include<vector>
using namespace std;

// 求解子岛屿的数量
// 算法: dfs
// 思路: 比如岛屿B所在的区域在grid1当中所在的区域为海水, 那么B岛屿就不是A的子岛屿
class Solution{
private:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1){
            return;
        }
        if(grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n = grid1.size(), m = grid1[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1 && grid1[i][j] == 0){
                    dfs(grid2, i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1){
                    res++;
                    dfs(grid2, i, j);
                }
            }
        }
        return res;
    }
};