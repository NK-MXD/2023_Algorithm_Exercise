/*
 * @Date: 2023-05-15 20:52:25
 * @LastEditTime: 2023-05-15 21:42:55
 * @题目描述: 有0-n-1个资源, 有一个资源列表{{a, b}, {c, d}...}, {a, b}表示b依赖a, 求解一个资源的初始化顺序
 * @思路解法: 拓扑排序, BFS算法
 * @优化思路: (这里提另一种算法: DFS实现思路: 用DFS来实现的话就相当于后续遍历的集合(注意onPath记录路径))
 * @关键算法: 拓扑排序, BFS算法
 * @复杂度: O(n)[遍历所有边] + O(n)[遍历所有节点] + O(n)[遍历所有节点]
 * @边界条件: 注意可能不连通
 * @静态Debug易错点: 本来是想将入度出度关系进行逆转, 但是逆转之后queue中新加节点不太好加入; 
 *                  注意如果有环要有visit数组标记是否遍历过(这个主要是用来判断有没有环, 如果我遍历过了那么就有环)
 * @相关题目: 力扣210
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 建图:
vector<int>* buildGraph(int n, vector<pair<int, int>>& deps, vector<int>& indegree){
    vector<int>* graph = new vector<int>[n];
    for(int i = 0; i < n; i++){
        graph[i] = vector<int>();
    }
    for(auto edge: deps){
        int from = edge.first;
        int to = edge.second;
        // 注意这里维护入度关系表
        graph[from].push_back(to);
        indegree[to]++;
    }
    return graph;
}

// 拓扑排序算法: BFS版本
vector<int> getRes(int n, vector<int>* graph, vector<int>& indegree){
    vector<int> res;
    queue<int> qlist;
    vector<bool> visit(n, false);
    for(int i = 0; i < n; i++){
        // 入度为0的为起始节点
        if(indegree[i] == 0){
            res.push_back(i);
            qlist.push(i);
            visit[i] = true;
        }
    }
    while(!qlist.empty()){
        int sz = qlist.size();
        for(int i = 0; i < sz; i++){
            int front = qlist.front();
            qlist.pop();
            for(auto to: graph[front]){
                // 判断是否有环
                if(!visit[to]){
                    qlist.push(to);
                    res.push_back(to);
                }
            }
        }
    }
    return res;
}

int main(){
    int n = 4;
    vector<pair<int, int>> deps = {{0, 1}, {0, 2}, {2, 3}};
    vector<int> indegree(n, 0); // 维护一个入度的关系表, 用来确认起点拓扑节点
    vector<int>* graph = buildGraph(n, deps, indegree);
    vector<int> res = getRes(n, graph, indegree);
    for(auto r: res){
        cout<<r<<" ";
    }
    return 0;
}
