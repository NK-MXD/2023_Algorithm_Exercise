/*
 * @Date: 2023-05-23 14:14:16
 * @LastEditTime: 2023-05-23 14:18:42
 * @题目描述: 
 * @思路解法: 本题有两种解法: 一种为递归的解决思路, 一种为for循环的解决思路, 都实现下
 * @优化思路: 
 * @关键算法: 
 * @复杂度: O(n)
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 递归方法:
    // ListNode* reverseList(ListNode* head) {
    //     // 递归基:
    //     if(!head || !head->next){
    //         return head;
    //     }
    //     ListNode* succ = head->next;
    //     ListNode* newhead = reverseList(head->next);
    //     succ->next = head;
    //     head->next = nullptr;
    //     return newhead;
    // }
    // 朴素遍历方法
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* succ;
        while(cur){
            succ = cur->next;
            cur->next = prev;
            prev = cur;
            cur = succ;
        }
        return prev;
    }
};
// @lc code=end

