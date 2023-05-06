#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 相关题目: 207
// 算法思路: 不仅要检测是否有环, 还需要将这些课程进行排列
// 对应的排列的可以用后序遍历
class Solution {
    vector<bool> visited;
    vector<bool> onPath;
    vector<int> res;
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
        res.push_back(i);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>* graph = buildGraph(numCourses, prerequisites);
        visited.resize(numCourses, false);
        onPath.resize(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            traverse(graph, i);
        }
        if(isCycle) return {};
        // 后序遍历的逆序
        reverse(res.begin(), res.end());
        return res;
    }
};