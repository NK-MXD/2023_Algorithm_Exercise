#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<functional>
using namespace std;

// 计算传遍整张图: 实际上是计算从k节点到其他所有节点最短路径中的最长路径是多少?
// 算法: Dij算法
class State{
public:
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;
    State(int id, int distFromStart) {
        this->id = id;
        this->distFromStart = distFromStart;
    }
    bool operator>(const State& other) const {
        return distFromStart > other.distFromStart;
    }
};

class Solution {
    // dijkstra算法
    vector<int> dijkstra(int start, vector<vector<pair<int,int>>>& graph){
        // 定义：distTo[i] 的值就是起点 start 到达节点 i 的最短路径权重
        vector<int> distTo(graph.size(), INT_MAX);
        // base case，start 到 start 的最短距离就是 0
        distTo[start] = 0;

        // 优先级队列，distFromStart 较小的排在前面
        priority_queue<State, vector<State>, function<bool(State, State)>> pq([](State a, State b){ return a.distFromStart > b.distFromStart; });
        // 从起点 start 开始进行 BFS
        pq.push(State(start, 0));

        while (!pq.empty()) {
            State curState = pq.top();
            pq.pop();
            int curNodeID = curState.id;
            int curDistFromStart = curState.distFromStart;

            if (curDistFromStart > distTo[curNodeID]) {
                continue;
            }

            // 将 curNode 的相邻节点装入队列
            for (auto neighbor : graph[curNodeID]) {
                int nextNodeID = neighbor.first;
                int distToNextNode = distTo[curNodeID] + neighbor.second;
                // 更新 dp table
                if (distTo[nextNodeID] > distToNextNode) {
                    distTo[nextNodeID] = distToNextNode;
                    pq.push(State(nextNodeID, distToNextNode));
                }
            }
        }
        return distTo;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 节点编号是从 1 开始的，所以要一个大小为 n + 1 的邻接表
        vector<vector<pair<int, int>>> graph(n + 1);
        // 构造图
        for (const vector<int>& edge : times) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            // from -> list[(to, weight)]
            // 邻接表存储图结构，同时存储权重信息
            graph[from].push_back(make_pair(to, weight));
        }
        // 启动 dijkstra 算法计算以节点 k 为起点到其他节点的最短路径
        vector<int> distTo = dijkstra(k, graph);

        // 找到最长的那一条最短路径
        int res = 0;
        for (int i = 1; i < distTo.size(); i++) {
            if (distTo[i] == INT_MAX) {
                // 有节点不可达，返回 -1
                return -1;
            }
            res = max(res, distTo[i]);
        }
        return res;
    }
};  