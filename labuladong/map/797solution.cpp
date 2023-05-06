#include<iostream>
#include<vector>
using namespace std;

// 给定n个节点的图, 找出从0到n-1的所有路径
// 算法: dfs遍历算法
// 问题: 在下面所在的区域
class Solution {
    vector<vector<int>> res;
    void traverse(vector<vector<int>>& graph, int i, vector<int>& path){
        int n = graph.size();
        // 加入节点
        path.push_back(i);
        if(i == n - 1){
            res.push_back(path);
            // 这里不要用return, 这是因为遍历之后会pop_back掉所有的当前遍历加入的值
            // 用return少了一次n - 1
        }
        for(auto g: graph[i]){
            traverse(graph, g, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        traverse(graph, 0, path);
        return res;
    }
};