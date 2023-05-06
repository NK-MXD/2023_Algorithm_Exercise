#include<iostream>
#include<vector>
using namespace std;

// 有些课程有先修课程, 要修该课程必须先修先修课程, 查看是否可以修完课程
// 算法: 先建立邻接表, 然后只要没有环就可以完成
class Solution {
    vector<bool> visited;
    vector<bool> onPath;
    bool isCycle = false;
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
        if(visited[i] || isCycle)
            return;
        visited[i] = true;
        onPath[i] = true;
        for(auto s: graph[i]){
            traverse(graph, s);
        }
        onPath[i] = false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>* graph = buildGraph(numCourses, prerequisites);
        visited.resize(numCourses, false);
        onPath.resize(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            traverse(graph, i);
        }
        return !isCycle;
    }
};