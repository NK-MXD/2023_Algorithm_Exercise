## 图的遍历算法

类比树的遍历方式:
```cpp
/* 多叉树遍历框架 */
void traverse(TreeNode* root) {
    if (root == nullptr) return;
    // 前序位置
    for (TreeNode* child : root->children) {
        traverse(child);
    }
    // 后序位置
}
```

图的遍历方式就是将对应的child节点转化为邻接表中的节点, 另外还需要考虑环

```cpp
vector<bool> visited;
vector<bool> onPath;
void traverse(Graph graph, int s) {
    if (visited[s]) return;
    // 经过节点 s，标记为已遍历
    visited[s] = true;
    // 做选择：标记节点 s 在路径上
    onPath[s] = true;
    for (int neighbor : graph.neighbors(s)) {
        traverse(graph, neighbor);
    }
    // 撤销选择：节点 s 离开路径
    onPath[s] = false;
}
```

## Union-find 并查集算法

一种很方便的应用于图的连通性的数据结构

## dijkstra算法:

```cpp
// Dij算法可以看做是一个带备忘录形式的BFS算法
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
    bool operator()(State a, State b) {
        return a.distFromStart > b.distFromStart;
    }
};
// 返回节点 from 到节点 to 之间的边的权重
int weight(int from, int to);

// 输入节点 s 返回 s 的相邻节点
vector<int> adj(int s);

// 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
vector<int> dijkstra(int start, vector<int> graph[]){
    int n = graph->size();
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    vector<int> distTo(n, INT_MAX);
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;
    // 优先级队列，distFromStart 较小的排在前面
    priority_queue<State, vector<State>> pq;
    // 从起点 start 开始进行 BFS
    pq.push(State(start, 0));
    while (!pq.empty()) {
        State curState = pq.top();
        pq.pop();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        if (curDistFromStart > distTo[curNodeID]) {
            // 已经有一条更短的路径到达 curNode 节点了
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (int nextNodeID: adj(curNodeID)) {
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight(curNodeID, nextNodeID);
            if (distTo[nextNodeID] > distToNextNode) {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.push(State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTo;
}
```