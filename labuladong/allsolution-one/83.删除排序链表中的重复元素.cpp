/*
 * @Date: 2023-05-23 16:26:18
 * @LastEditTime: 2023-05-23 18:01:40
 * @题目描述: 
 * @思路解法: 快慢指针
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 需要把slow之后的节点都断开
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow, * quick;
        slow = quick = head;
        while(quick){
            if(quick->val != slow->val){
                slow->next = quick;
                slow = slow->next;
            }            
            quick = quick->next;
        }
        // 需要把slow之后的节点都断开
        if(slow) slow->next = nullptr;
        return head;
    }
};
// @lc code=end

