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
