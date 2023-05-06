#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<numeric>
using namespace std;

// 返回连接所有城市的最低成本，每对城市之间至少有一条路径。如果无法连接所有 n 个城市，返回 -1
// 算法: 并查集, 克鲁斯卡尔算法
// 思想: 所谓最小生成树, 图中所有节点都为连通的, 权重和最小
// 贪心思路: 将所有边按照权重从小到大排序，从权重最小的边开始遍历，
// 如果这条边和mst中的其它边不会形成环，则这条边是最小生成树的一部分，将它加入mst集合；
// 否则，这条边不是最小生成树的一部分，不要把它加入mst集合。

// 另一种算法是Prim最小生成树算法: 每次找权重最小的横切边, 使用优先队列(最下面)
class UF{
private:
    int count;
    int *parent;
public:
    UF(int n){
        this->count = n;
        parent = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    // 将节点 p 和节点 q 连通
    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ)
            return;
        
        parent[rootQ] = rootP;
        // 两个连通分量合并成一个连通分量
        count--;
    }

    // 判断节点 p 和节点 q 是否连通
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 返回图中的连通分量个数
    int count_() {
        return count;
    }
};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // 城市编号为 1...n，所以初始化大小为 n + 1
        UF uf(n + 1);
        // 对所有边按照权重从小到大排序
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        int mst = 0;
        for (auto edge : connections) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            // 若这条边会产生环，则不能加入 mst
            if (uf.connected(u, v)) {
                continue;
            }
            // 若这条边不会产生环，则属于最小生成树
            mst += weight;
            uf.union_(u, v);
        }
        // 但因为节点 0 没有被使用，所以 0 会额外占用一个连通分量
        return uf.count_() == 2 ? mst : -1;
    }
};

class Prim {
public:
    explicit Prim(vector<vector<pair<int, int>>> &graph): m_graph(graph) {
        m_weight.resize(m_graph.size());
        m_visited.resize(m_graph.size());
        m_parent.resize(m_graph.size(), -1);

        for (int i = 0; i < m_graph.size(); ++i) {
            m_visited[i] = false;
            m_weight[i] = INT_MAX;
        }
    }

    int weightSum() {
        return accumulate(m_weight.begin(), m_weight.end(), 0);
    }

    bool allConnected() {
        visit(0);
        for (const auto& visited : m_visited) {
            if (!visited) {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<pair<int, int>>> &m_graph;
    vector<int> m_weight;
    vector<int> m_parent;
    vector<bool> m_visited;

    void visit(int current) {
        const auto& adjacents = m_graph[current];
        m_visited[current] = true;

        for (const auto& adjacent : adjacents) {
            const auto& [node, weight] = adjacent;
            if (m_visited[node]) {
                continue;
            }

            if (weight >= m_weight[node]) {
                continue;
            }

            m_weight[node] = weight;
            m_parent[node] = current;
            visit(node);
        }
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n); // 转化成无向图邻接表的形式
        for (auto& connection: connections) {
            int u = connection[0] - 1; // 题目给的节点编号是从 1 开始的
            int v = connection[1] - 1;
            int weight = connection[2];
            graph[u].push_back({v, weight}); // 「无向图」其实就是「双向图」
            graph[v].push_back({u, weight});
        }

        Prim prim(graph);
        if (!prim.allConnected()) {
            // 最小生成树无法覆盖所有节点
            return -1;
        }
        return prim.weightSum();
    }
};