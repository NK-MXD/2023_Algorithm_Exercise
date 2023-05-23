/*
 * @Date: 2023-05-18 13:14:19
 * @LastEditTime: 2023-05-18 14:26:48
 * @题目描述: 
 * @思路解法: 将所有的丑数列表中最小的那个加入到最后的结果当中
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 注意 res[indexk] * primek 可能越界
 * @相关题目: 214, 21
 */
/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */
#include<vector>
#include<queue>
using namespace std;

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<vector<long>, vector<vector<long>>, greater<vector<long>>> pq;
        for(auto i: primes){
            pq.push({1, i, 1});
        }
        vector<long> res(n + 1, 0);
        int p = 1;
        while(p <= n ){
            vector<long> pair = pq.top();
            pq.pop();
            long numk = pair[0];
            long primek = pair[1];
            long indexk = pair[2];
            if(numk != res[p - 1]){
                res[p] = numk;
                p++;
            }
            vector<long> nextPair = { res[indexk] * primek, primek, indexk + 1 };
            pq.push(nextPair);
        }
        return res[n];
    }
};
// @lc code=end

