/*
 * @Date: 2023-05-14 10:41:58
 * @LastEditTime: 2023-05-14 10:55:45
 * @题目描述: n个人围成一圈, 每次从1开始编号, 移动k步传给下一个人, 下一个人移动2k步传给下一个
 * 求有人两次接球后一次也没接到的人的列表
 * @思路解法: 可以用一个map来代表接到球的人
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: map[1] = 1;
 * @静态Debug易错点: 编号从1开始; return nexti == 0? N: nexti;
 * @相关题目: 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
    int N;   // 人数
    // 从n编号开始传times接到球的人的编号
    int getNext(int n, int times){
        int nexti = n + times;
        if(nexti > N){
            nexti = nexti % N;
        }
        return nexti == 0? N: nexti;
    }
public:
    vector<int> circularGameLosers(int n, int k) {
        N = n;
        int no = 1;
        int i = 1;
        unordered_map<int, int> map;
        map[no] = 1;
        while(true){
            no = getNext(no, i*k);
            if(!map.count(no)){
                map[no] = 1;
            }
            else{
                map[no] = 1;
                break;
            }
            i++;
        }
        vector<int> res;
        for(int j = 1; j <= N; j++){
            if(!map.count(j)){
                res.push_back(j);
            }
        }
        return res;
    }
};