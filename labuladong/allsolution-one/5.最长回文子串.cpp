/*
 * @Date: 2023-05-23 16:26:18
 * @LastEditTime: 2023-05-23 17:53:18
 * @题目描述: 
 * @思路解法: 回文子串的判定方法是从中心开始进行判定, 从中心位置进行遍历最长的回文子串
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 如果getPalindromeLength返回的是长度的话, 那么截取字符串的起始位置就找不到了!!
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
    string getPalindromeString(string s, int lo, int hi){
        int n = s.length();
        while(lo >= 0 && hi < n){
            if(s[lo] != s[hi]){
                break;
            }
            lo--;
            hi++;
        }
        return s.substr(lo + 1, hi - lo - 1);
    }
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++){
            string l1 = getPalindromeString(s, i, i);
            string l2 = getPalindromeString(s, i, i + 1);
            res = l1.length() > res.length() ? l1: res;
            res = l2.length() > res.length() ? l2: res;
        }
        return res;
    }
};
// @lc code=end

