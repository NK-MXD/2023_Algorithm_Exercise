#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<functional>
using namespace std;

// 求解路径的最小消耗
// 算法dij算法
class State{
public:
    // 图节点的 id
    int x, y;
    // 从 start 节点到当前节点的距离
    int dist;
    State(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};

class Solution {
    // 计算相邻坐标的值
    vector<vector<int>> adj(const vector<vector<int>>& heights, int curX, int curY) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ret;
        if (curX > 0) {
            ret.push_back({curX - 1, curY});
        }
        if (curY > 0) {
            ret.push_back({curX, curY - 1});
        }
        if (curX < m - 1) {
            ret.push_back({curX + 1, curY});
        }
        if (curY < n - 1) {
            ret.push_back({curX, curY + 1});
        }
        return ret;
    }
public:
    // 直接计算最短路径, 从(0,0) 到 (m - 1, n - 1) 的最小值
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effortTo(m, vector<int>(n, INT_MAX));
        effortTo[0][0] = 0;// 起始点的体力消耗为0
        // 优先级队列，effortFromStart 较小的排在前面
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push(State(0, 0, 0));
        while(!pq.empty()) {
            State s = pq.top();
            pq.pop();
            int x = s.x, y = s.y;
            int e = s.dist;
            if(x == m - 1 && y == n - 1)
                return e;
            if(e > effortTo[x][y])
                continue;
            for(auto vec: adj(heights, x, y)){
                int nextx = vec[0];
                int nexty = vec[1];
                int nexte = max(
                    effortTo[x][y], 
                abs(heights[x][y] - heights[nextx][nexty]));
                if(effortTo[nextx][nexty] > nexte){
                    effortTo[nextx][nexty] = nexte;
                    pq.push(State(nextx, nexty, nexte));
                }
            }
        }
        return -1;
    }
};