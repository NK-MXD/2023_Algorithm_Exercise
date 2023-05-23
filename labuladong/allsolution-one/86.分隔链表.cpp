/*
 * @Date: 2023-05-18 12:01:13
 * @LastEditTime: 2023-05-18 12:30:51
 * @题目描述: 
 * @思路解法: 基本的思路就是分为两个链表组, 其中一个串联小于x的节点, 另一个串联大于x的节点
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 注意去掉原来节点的前驱后继关系
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

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
// #include<vector>
// #include<iostream>
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* p1 = dummy1, *p2 = dummy2;
        while(head != nullptr){
            int val = head->val;
            if(val < x){
                p1->next = head;
                p1 = p1->next;
            }else{
                p2->next = head;
                p2 = p2->next;
            }
            ListNode* temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
// @lc code=end

