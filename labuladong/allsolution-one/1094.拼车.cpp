/*
 * @Date: 2023-05-23 22:23:36
 * @LastEditTime: 2023-05-23 22:38:20
 * @题目描述: 
 * @思路解法: 先求差分数组, 然后求出旅途中最多的乘客的数量, 然后进行判断
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 目的地下次不算, 注意是在right + 1处减去对应的增长值
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> diff;
    void increment(int left, int right, int inc){
        diff[left] += inc;
        if(right + 1 < diff.size()){
            diff[right + 1] -= inc;
        }
    }

    int getMax(){
        int num = diff[0], maxNum = diff[0];
        int n = diff.size();
        for(int i = 1; i < n; i++){
            num += diff[i];
            maxNum = max(num, maxNum);
        }
        return maxNum;
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 初始化差分数组
        int n = trips.size();
        diff.resize(1001, 0);
        for(auto trip: trips){
            int inc = trip[0];
            int left = trip[1];
            int right = trip[2] - 1;
            increment(left, right, inc);
        }
        return getMax() > capacity ? false: true;
    }
};
// @lc code=end

