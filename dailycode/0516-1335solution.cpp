/*
 * @Date: 2023-05-16 00:49:37
 * @LastEditTime: 2023-05-16 00:49:50
 * @题目描述: 你需要制定一份 d 天的工作计划表。工作之间存在依赖，要想执行第 i 项工作，你必须完成全部 j 项工作;
 * 你每天 至少 需要完成一项任务。工作计划的总难度是这 d 天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大难度。
 * 返回整个工作计划的 最小难度 。如果无法制定工作计划，则返回 -1 。
 * @思路解法: 感觉像是先进行一个集合的划分问题, 将它划分为d个集合(需要是连续的), 然后求解集合中最大值的和最小
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {

    }
};