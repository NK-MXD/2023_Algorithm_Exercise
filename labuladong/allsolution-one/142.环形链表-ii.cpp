/*
 * @Date: 2023-05-18 13:03:20
 * @LastEditTime: 2023-05-18 13:04:12
 * @题目描述: 
 * @思路解法: 本题的思路解法在于当两个快慢指针相遇时, 设置其中一个指针的值为起始指针, 再次相遇就是该节点
 * @优化思路: 
 * @关键算法: 
 * @复杂度: O(2n) O(1)
 * @边界条件: 
 * @静态Debug易错点: if(quick == nullptr || quick->next == nullptr) 这个别忘了第二个或条件判断
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// #include<iostream>
// #include<vector>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow, * quick;
        slow = head;
        quick = head;
        while(quick != nullptr && quick->next != nullptr){
            slow = slow->next;
            quick = quick->next->next;
            if(slow == quick) break;
        }
        if(quick == nullptr || quick->next == nullptr){
            return nullptr;
        }
        quick = head;
        while(slow != quick){
            slow = slow->next;
            quick = quick->next;
        }
        return slow;
    }
};
// @lc code=end

