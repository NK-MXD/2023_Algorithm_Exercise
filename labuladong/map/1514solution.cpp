#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<functional>
using namespace std;

// 求解从起点到终点成功概率最大的路径
class Solution {
    double dijkstra(int start, int end, vector<list<pair<int, double>>>& graph) {
        // 定义：probTo[i] 的值就是节点 start 到达节点 i 的最大概率
        vector<double> probTo(graph.size(), -1);
        // dp table 初始化为一个取不到的最小值
        // base case，start 到 start 的概率就是 1
        probTo[start] = 1;
    
        // 优先级队列，probFromStart 较大的排在前面
        priority_queue<pair<double, int>> pq;
        // 从起点 start 开始进行 BFS
        pq.push({1, start});
    
        while (!pq.empty()) {
            auto [curProbFromStart, curNodeID] = pq.top();
            pq.pop();
    
            // 遇到终点提前返回
            if (curNodeID == end) {
                return curProbFromStart;
            }
    
            if (curProbFromStart < probTo[curNodeID]) {
                // 已经有一条概率更大的路径到达 curNode 节点了
                continue;
            }
            // 将 curNode 的相邻节点装入队列
            for (auto [nextNodeID, weight] : graph[curNodeID]) {
                // 看看从 curNode 达到 nextNode 的概率是否会更大
                double probToNextNode = probTo[curNodeID] * weight;
                if (probTo[nextNodeID] < probToNextNode) {
                    probTo[nextNodeID] = probToNextNode;
                    pq.push({probToNextNode, nextNodeID});
                }
            }
        }
        // 如果到达这里，说明从 start 开始无法到达 end，返回 0
        return 0.0;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<list<pair<int, double>>> graph(n);
        // 构造邻接表结构表示图
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double weight = succProb[i];
            // 无向图就是双向图；先把 int 统一转成 double，待会再转回来
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }

        return dijkstra(start, end, graph);
    }
};