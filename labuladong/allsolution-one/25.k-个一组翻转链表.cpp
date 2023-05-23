/*
 * @Date: 2023-05-23 15:15:10
 * @LastEditTime: 2023-05-23 15:26:51
 * @题目描述: 
 * @思路解法: 用92题的递归思路可以很方便求解k个一组进行翻转, 对于不是k的整数倍的节点, 可以采用快慢指针的方式
 * @优化思路: 不用使用快慢指针, 只要在n的那一部分判断是否n会小于1就可
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            return head;
        }
        ListNode* newhead = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
public:
    // 把这个函数看作是以节点head开头的, 以k个一组进行翻转得到的头结点
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* left, * right;
        left = right = head;
        for(int i = 0; i < k; i++){
            if(right == nullptr) return head;
            right = right->next;
        }
        ListNode* newhead = reverseN(left, k);
        left->next = reverseKGroup(right, k);
        return newhead;
    }
};
// @lc code=end

