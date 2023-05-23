/*
 * @Date: 2023-05-23 15:36:17
 * @LastEditTime: 2023-05-23 15:37:24
 * @题目描述: 
 * @思路解法: 递归思路
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 25
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    // 递归实现, 看做是以head开头的交换两两节点, 然后返回值为交换后的链表的头结点
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* leftnode = head;
        ListNode* rightnode = head->next->next;
        ListNode* newhead = leftnode->next;
        leftnode->next->next = leftnode;
        leftnode->next = swapPairs(rightnode);
        return newhead;
    }
};
// @lc code=end

