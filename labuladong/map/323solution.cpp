#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 求解无向图中的连通分量的个数
// 算法: 并查集
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
    int countComponents(int n, vector<vector<int>>& edges) {
        UF uf(n);
        // 将每个节点进行连通
        for (const auto& e : edges) {
            uf.union_(e[0], e[1]);
        }
        // 返回连通分量的个数
        return uf.count_();
    }
};