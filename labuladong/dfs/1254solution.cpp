#include<iostream>
#include<vector>
using namespace std;
 
// 求解封闭岛屿的数量
// 算法: dfs
// 思路: 只需要将靠边的岛屿用dfs算法进行"淹没"
class Solution{
private:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i > n - 1 || j < 0 || j > m - 1){
            return;
        }
        if(grid[i][j] == '1'){
            return;
        }
        grid[i][j] = '1';
        for(auto dir: direction){
            dfs(grid, i + dir[0], j + dir[1]);
        }
    };
public:
    int closedIsland(vector<vector<int>>& grid){
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            if(grid[i][0] == '0'){
                dfs(grid, i, 0);
            }
            if(grid[i][m - 1] == '0'){
                dfs(grid, i, m - 1);
            }
        }
        for(int j = 0; j < m; j++){
            if(grid[0][j] == '0'){
                dfs(grid, 0, j);
            }
            if(grid[n - 1][j] == '0'){
                dfs(grid, n - 1, j);
            }
        }
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(grid[i][j] == '0'){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    };
};