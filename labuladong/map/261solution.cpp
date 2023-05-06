#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 给定图判断能否构成树
// 算法思路: 一种方法是使用dfs遍历思路, 判断是否存在回头路
// 另一种方法是使用并查集这种数据结构, 判定的思路很简单, 如果是连接已经是连通的两个变量, 就出现了环
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
    bool validTree(int n, vector<vector<int>>& edges) {
        // 初始化 0...n-1 共 n 个节点
        UF uf(n);
        // 遍历所有边，将组成边的两个节点进行连接
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // 若两个节点已经在同一连通分量中，会产生环
            if (uf.connected(u, v)) {
                return false;
            }
            // 这条边不会产生环，可以是树的一部分
            uf.union_(u, v);
        }
        // 要保证最后只形成了一棵树，即只有一个连通分量
        return uf.count_() == 1;
    }
};