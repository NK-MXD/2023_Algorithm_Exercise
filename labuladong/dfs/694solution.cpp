#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

// 计算不同岛屿的数量
// 算法: dfs
// 思路: 对于每一个岛屿只需要存储其中的方向信息, 方向信息只需要记录dfs的顺序即可
class Solution{
private:
    void dfs(vector<vector<int>>& grid, int i, int j, string record, int dir){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i > n - 1 || m < 0 || m > m - 1){
            return;
        }
        if(grid[i][j] == 0){
            return;
        }
        grid[i][j] = 1;
        record += to_string(dir) + record;
        dfs(grid, i + 1, j, record, 1);
        dfs(grid, i - 1, j, record, 2);
        dfs(grid, i, j + 1, record, 3);
        dfs(grid, i, j - 1, record, 4);
        record += to_string(dir) + record;
    }
public: 
    int numDistinctIslands(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        unordered_set<string> res;
        string record = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    record = "";
                    // 其中的record记录的是递归的参数, 0记录的是方向信息
                    dfs(grid, i, j, record, 0);
                    res.insert(record);
                }
            }
        }
        return res.size();
    }
};