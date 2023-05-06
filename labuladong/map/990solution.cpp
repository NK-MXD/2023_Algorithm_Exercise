#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 写一个算法，如果 equations 中所有算式都不会互相冲突，返回 true，否则返回 false
// 算法思路: 并查集巧解题: 其中==相当于将两个变量直接相关联起来, !=判断两个变量进行连通
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
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (const string& eq : equations) {
            if (eq[1] == '=') {
                char x = eq[0];
                char y = eq[3];
                uf.union_(x - 'a', y - 'a');
            }
        }
        for (const string& eq : equations) {
            if (eq[1] == '!') {
                char x = eq[0];
                char y = eq[3];
                if (uf.connected(x - 'a', y - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};