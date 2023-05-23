/*
 * @Date: 2023-05-23 14:29:39
 * @LastEditTime: 2023-05-23 15:12:13
 * @题目描述: 
 * @思路解法: 可以采用朴素遍历的思想, 加计数, 也可以采用递归遍历的思想
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 注意边界条件下head->next可以为nullptr
 * @静态Debug易错点: 问题: 我朴素的遍历不会了........[fix]
 * @相关题目: 206
 */
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* successor = nullptr;  // 后驱节点
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            successor = head->next;
            return head;
        }
        ListNode* newhead = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return newhead;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // base case是以head为开头的链表的翻转
        if(left == 1){
            return reverseN(head, right);  // 返回的结果是翻转之后链表的头结点
        }
        if(left < 1){
            return nullptr;
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};
// @lc code=end

