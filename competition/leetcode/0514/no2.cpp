/*
 * @Date: 2023-05-14 11:00:03
 * @LastEditTime: 2023-05-14 11:11:58
 * @题目描述: 长度为n的数组是通过长度为n的数组相邻位异或得到的, derived[i] = original[i] ⊕ original[0]
 * derived[i] = original[i] ⊕ original[i + 1], 给定一个derive数组, 判断是否存在一个original数组
 * @思路解法: 可以判断第一位是什么并不影响, 假设第一位是0, 判断最后一位是否符合即可
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 有个问题, 异或我不会 ^=
 * @相关题目: 
 */
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n, 0);
        for(int i = 1; i < n; i++){
            original[i] = derived[i - 1] ^= original[i - 1];
        }
        return (original[n - 1] ^= original[0]) == derived[n - 1]?true:false;
    }
};