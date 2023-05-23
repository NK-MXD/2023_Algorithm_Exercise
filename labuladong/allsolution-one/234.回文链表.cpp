/*
 * @Date: 2023-05-23 15:45:34
 * @LastEditTime: 2023-05-23 15:45:50
 * @题目描述: 
 * @思路解法: 设置一个快慢指针找到中点, 然后通过中点之后和之前的节点进行对比
 * @优化思路: 错了!回文是对折, 不是平移, 但是翻转之后就可以进行比较了
 * @关键算法: 翻转链表
 * @复杂度: O(n/2) + O(n/2) + O(n/2)
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 206
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* reverse(ListNode* head){
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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow, *quick;
        slow = quick = head;
        while(quick && quick->next){
            slow = slow->next;
            quick = quick->next->next;
        }
        // quick == nullptr 为偶数情况
        if(quick == nullptr){
            slow = reverse(slow);
            while(slow){
                if(slow->val != head->val) return false;
                slow = slow->next;
                head = head->next;
            }
        }
        // quick->next == nullptr 为奇数情况
        else{
            slow = reverse(slow->next);
            while(slow){
                if(slow->val != head->val) return false;
                slow = slow->next;
                head = head->next;
            }
        }
        return true;
    }
};
// @lc code=end

