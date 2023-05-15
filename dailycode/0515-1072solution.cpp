/*
 * @Date: 2023-05-15 23:37:32
 * @LastEditTime: 2023-05-15 23:37:51
 * @题目描述: 给定矩阵, 可以选择列翻转其上每个单元格的值, 返回行与行之间所有值都相等的最大个数
 * @思路解法: 感觉都翻转为0和都翻转为1差不多, 都翻转为0吧, 从每行开始, 翻转集合的个数的最大值
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: flip不能用int什么来表示会溢出, 用string表示最好
 * @相关题目: 
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // flip用字节码编号吧
        string flip1, flip2;
        unordered_map<string, int> map;
        for(int i = 0; i < m; i++){
            flip1.clear();
            flip2.clear();
            for(int j = 0; j < n; j++){
                flip1 += matrix[i][j] == 0? '0':'1';
                flip2 += matrix[i][j] == 1? '0':'1';
            }
            map[flip1]++;
            map[flip2]++;
        }
        int res = 0;
        for(auto m: map){
            res = max(res, m.second);
        }
        return res;
    }
};