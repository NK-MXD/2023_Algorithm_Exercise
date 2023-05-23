/*
 * @Date: 2023-05-18 13:17:39
 * @LastEditTime: 2023-05-18 13:45:26
 * @题目描述: 
 * @思路解法: 列表当中有一个值, 每次都可以进行一轮质数乘法求得下一轮次的值, 插入大根堆中
 * @优化思路: 上述思路有问题, 你怎么知道那次相乘的结果恰好是第n项那个呢? 粗暴得想3k就一定可以得到相应的结果, 但是第k个你知道吗?使用堆
 * 可以参考合并n个有序链表的想法, 将能被2整除的丑数链表和能被3整除 5整除的丑数链表合并即可
 * @关键算法: 
 * @复杂度: O(nlogn)
 * @边界条件: 
 * @静态Debug易错点: 不能简单将235的倍数加入, 比如14 = 2 X 7, 7并非丑数因子
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int p2(1), p3(1), p5(1);
        int list2(1), list3(1), list5(1);
        vector<int> res(n + 1, 1);
        int p = 1;
        while(p <= n){
            int minnum = min(min(list2, list3), list5);
            res[p] = minnum;
            p++;
            if(minnum == list2){
                list2 = 2 * res[p2];
                p2++;
            }
            if(minnum == list3){
                list3 = 3 * res[p3];
                p3++;
            }
            if(minnum == list5){
                list5 = 5 * res[p5];
                p5++;
            }
        }
        return res[n];

    }
};
// @lc code=end

