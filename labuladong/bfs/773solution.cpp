#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

// 求解迷版的最小移动次数
// 算法: bfs
// 思路: 先铁憨憨使用dfs

// 难点: 如何写移动板块的代码, 当前板块如何存放(这里使用的存放方式为string类型, 这里使用的移动代码为数组映射移动代码)
class Solution {
    vector<int>* v = new vector<int>[6];
    string swap(string s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        return s;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        v[0] = {1, 3};
        v[1] = {0, 2, 4};
        v[2] = {1, 5};
        v[3] = {0, 4};
        v[4] = {1, 3, 5};
        v[5] = {2, 4};
        string target = "123450";
        string s;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                s += '0' + board[i][j];
            }
        }
        queue<string> q;
        int step = 0;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            int sz = q.size();
            for(int k = 0; k < sz; k++){
                string str = q.front();
                q.pop();
                if(str == target){
                    return step;
                }
                auto ii = find(str.begin(), str.end(), '0');
                int i = ii - str.begin();
                vector<int> vec = v[i];
                for(auto index: vec){
                    string news = swap(str, i, index);
                    if(!visited.count(news)){
                        q.push(news);
                        visited.insert(news);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};