#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stdio.h>
#include<unordered_set>
#include<algorithm>
using namespace std;

// 转盘密码锁
// 算法: bfs
// 思路: 最简单的情况: 不考虑dead, 直接到target, 可以是每次计算得到对应的变换后的密码锁加入到队列当中, 直到队列当中包含了target
// 优化思路: 可以使用双向的bfs来进行遍历, 此时目标target就是确定两个集合是否有交集
class Solution{
    string Up(string s, int i){
        if(s[i] == '9'){
            s[i] = '0';
        }else{
            s[i]++;
        }
        return s;
    }
    string Down(string s, int i){
        if(s[i] == '0'){
            s[i] = '9';
        }else{
            s[i]--;
        }
        return s;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads;
        for (string s : deadends) {
            deads.insert(s);
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push("0000");
        visited.insert("0000");
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string str = q.front();
                q.pop();
                if(str == target){
                    return step;
                }
                if(deads.count(str)) continue;
                visited.insert(str);
                for(int j = 0; j < 4; j++){
                    string up = Up(str, j);
                    string down = Down(str, j);
                    if(!deads.count(up) && !visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    if(!deads.count(down) && !visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    int openLock2(vector<string>& deadends, string target) {
        unordered_set<string> q1, q2, visited;
        unordered_set<string> deads(deadends.begin(), deadends.end());
        int step = 0;
        q1.insert("0000");
        q2.insert(target);
        while(!q1.empty() && !q2.empty()){
            unordered_set<string> temp;
            for(auto cur: q1){
                if(deads.count(cur))
                    continue;
                if(q2.count(cur))
                    return step;
                visited.insert(cur);
                for(int j = 0; j < 4; j++){
                    string up = Up(cur, j);
                    string down = Down(cur, j);
                    if(!deads.count(up) && !visited.count(up)){
                        temp.insert(up);
                    }
                    if(!deads.count(down) && !visited.count(down)){
                        temp.insert(down);
                    }
                }
            }
            step++;
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
};