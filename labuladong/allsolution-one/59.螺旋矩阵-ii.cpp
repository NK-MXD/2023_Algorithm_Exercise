/*
 * @Date: 2023-05-23 22:53:48
 * @LastEditTime: 2023-05-23 23:10:32
 * @题目描述: 
 * @思路解法: 设定每次遍历的上下左右边界, 每次到达边界时进行调整
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int upboard = 0, downboard = n, leftboard = 0, rightboard = n;
        // 都是左闭右开
        int num = 1;
        while(num <= n * n){
            // 从顶部由左到右遍历
            if(upboard < downboard){
                for(int i = leftboard; i < rightboard; i++){
                    res[upboard][i] = num++;
                }
                upboard++;
            }
            // 从右边由上到下遍历
            if(leftboard < rightboard){
                for(int i = upboard; i < downboard; i++){
                    res[i][rightboard - 1] = num++;
                }
                rightboard--;
            }
            // 从底部由右到左遍历
            if(upboard < downboard){
                for(int i = rightboard - 1; i >= leftboard; i--){
                    res[downboard - 1][i] = num++;
                }
                downboard--;
            }  
            // 从左边由下到上遍历
            if(leftboard < rightboard){
                for(int i = downboard - 1; i >= upboard; i--){
                    res[i][leftboard] = num++;
                }
                leftboard++;
            }
        }
        return res;


    }
};
// @lc code=end

