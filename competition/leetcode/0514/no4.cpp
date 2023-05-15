/*
 * @Date: 2023-05-14 11:55:13
 * @LastEditTime: 2023-05-14 13:21:41
 * @题目描述: 有顶点n个有无向边edge, 返回完全连通分量的个数, 完全连通分量是指任意两个边都连接
 * @思路解法: 可以使用dfs遍历, 不过需要使用边计数, 点计数, 来表示是否完全连通
 * @优化思路: 并查集暂时没有思路
 * @关键算法: 
 * @复杂度: O(2*edgenums)
 * @边界条件: 
 * @静态Debug易错点: E >>= 1; 因为为无向边, 每次加边会双向加边
 * @相关题目: 
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
    vector<bool> vis;
    void dfs(int v, vector<vector<int>>& graph, int& cntV, int& cntE){
        vis[v] = true;
        cntV++;
        for(auto e: graph[v]){
            cntE++;
            if(!vis[e]) dfs(e, graph, cntV, cntE);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vis.resize(n, false);
        vector<vector<int>> graph(n, vector<int>());
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int V = 0, E = 0;
                dfs(i, graph, V, E);
                E >>= 1;
                if(E == V*(V - 1) / 2) res++;
            }
        }
        return res;
    }
};
