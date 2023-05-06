#include<iostream>
#include<vector>
using namespace std;

// 本题目的描述是: 有n个工程, 每个工程都有一些前继工程需要完成, 判断要完成这些工程需要多少批
// 算法思路: 先使用buildGragh建立图, 然后使用遍历, 找到最大深度
class Solution {
    vector<bool> visited;
    vector<bool> onPath;
    bool isCycle = false;
    int depth = 0;
    int max_depth = 0;
    vector<int>* buildGraph(int n, vector<vector<int>>& prerequisites){
        vector<int>* graph = new vector<int>[n];
        for(int i = 0; i < n; i++){
            graph[i] = vector<int>();
        }
        for(auto edge: prerequisites){
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }
    void traverse(vector<int>* graph, int i){
        if(onPath[i] == true){
            isCycle = true;
        }
        if(visited[i] || isCycle){
            max_depth = max(max_depth, depth);
            return;
        }
        visited[i] = true;
        onPath[i] = true;
        depth++;
        for(auto s: graph[i]){
            traverse(graph, s);
        }
        onPath[i] = false;
        depth--;
    }
public:
    int canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>* graph = buildGraph(numCourses, prerequisites);
        visited.resize(numCourses, false);
        onPath.resize(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            traverse(graph, i);
        }
        if(isCycle) return -1;
        // 计算图的深度
        return max_depth;
    }
};