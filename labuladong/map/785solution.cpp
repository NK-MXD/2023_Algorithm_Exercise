#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 判断一个无向图是否为二分图
// 算法思路: 遍历图, visited标记善用
class Solution {
    // 记录图是否符合二分图性质
    bool ok = true;
    // 记录图中节点的颜色，false 和 true 代表两种不同颜色
    vector<bool> color;
    // 记录图中节点是否被访问过
    vector<bool> visited;
    // DFS 遍历框架
    void traverse(vector<vector<int>>& graph, int v) {
        // 如果已经确定不是二分图了，就不用浪费时间再递归遍历了
        if (!ok) return;

        visited[v] = true;
        for (int w : graph[v]) {
            if (!visited[w]) {
                // 相邻节点 w 没有被访问过
                // 那么应该给节点 w 涂上和节点 v 不同的颜色
                color[w] = !color[v];
                // 继续遍历 w
                traverse(graph, w);
            } else {
                // 相邻节点 w 已经被访问过
                // 根据 v 和 w 的颜色判断是否是二分图
                if (color[w] == color[v]) {
                    // 若相同，则此图不是二分图
                    ok = false;
                    return;
                }
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n, false);
        visited.resize(n, false);
        // 因为图不一定是联通的，可能存在多个子图
        // 所以要把每个节点都作为起点进行一次遍历
        // 如果发现任何一个子图不是二分图，整幅图都不算二分图
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                traverse(graph, v);
            }
        }
        return ok;
    }
};