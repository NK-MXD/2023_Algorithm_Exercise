/*
 * @Date: 2023-05-18 13:45:55
 * @LastEditTime: 2023-05-18 14:14:50
 * @题目描述: 
 * @思路解法: 本题和264题稍有不同, 在于丑数的定义变为了整数倍, 和之前的解法有些类似, 但是复杂度会超限(每次都是加一次效率太低了)
 * @优化思路: 进行二分搜索求解其中能够被abc整除的数的个数
 * @关键算法: 二分搜索
 * @复杂度: O(logn)
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 264
 */
/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 */
#include<vector>
using namespace std;

// @lc code=start
// 超时
// class Solution {
// public:
//     int nthUglyNumber(int n, int a, int b, int c) {
//         // int pa(0), pb(0), pc(0);
//         long numa(a), numb(b), numc(c);
//         long res;
//         int p = 0;
//         while(p < n){
//             long minnum = min(min(numa, numb), numc);
//             res = minnum;
//             p++;
//             if(minnum == numa){
//                 numa = numa + a;
//             }
//             if(minnum == numb){
//                 numb = numb + b;
//             }
//             if(minnum == numc){
//                 numc = numc + c;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        // int pa(0), pb(0), pc(0);
        int left = 1, right = (int)2e9;//[1, 2e9]
        while(left <= right){
            int mid = left + (right - left)/2;
            if(getNumOf(mid, a, b, c) < n){
                left = mid + 1;// 右侧[mid + 1, ...]
            }else{
                right = mid - 1;// 左侧[..., mid]
            }
        }
        return left;
    }
    long getNumOf(int num, int a, int b, int c){
        long seta = num / a, setb = num / b, setc = num / c;
        long setab = num / lcm(a, b);
        long setac = num / lcm(a, c);
        long setbc = num / lcm(b, c);
        long setabc = num / lcm(lcm(a, b), c);
        return seta + setb + setc - setab - setbc - setac + setabc;
    }

    // 最小公约数就是乘积除以最大公约数
    long lcm(long a, long b){
        return a * b / gcd(a, b);
    }

    // 最大公约数的求法就是辗转相除法
    long gcd(long a, long b){
        if(a < b){
            return gcd(b, a);
        }
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }
};
// @lc code=end

