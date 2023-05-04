#include<iostream>
#include<vector>
using namespace std;

// 计算岛屿的数量
// 算法: dfs
// 思路: 每次发现一块陆地++, 然后使用dfs算法将岛屿填为海
class Solution{
private:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i >= n|| j < 0 || j >= m){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '1';
        for(auto dir: direction){
            dfs(grid, i + dir[0], j + dir[1]);
        }
    }
public:
    int numIsLands(vector<vector<int>> grid){
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m;j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};