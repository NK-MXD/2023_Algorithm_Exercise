/*
 * @Date: 2023-05-23 18:05:12
 * @LastEditTime: 2023-05-23 19:30:53
 * @题目描述: 
 * @思路解法: 与83不同的是只要数字重复了就删去, 同样快慢指针加一个flag标记
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 边界太容易出错了, 下面注明了可能出错的点
 * @相关题目: 83
 */
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        if(head == nullptr) return nullptr;
        ListNode* result = nullptr;
        ListNode* slow, *quick;
        slow = head;
        quick = slow->next;
        if(quick == nullptr) return head;
        bool flag = true;
        ListNode* cur;
        while(quick != nullptr){
            if(quick->val == slow->val){
                flag = false;
            }else{
                if(flag){
                    if(result == nullptr){
                        result = slow;
                        cur = result;
                        // 易错点1: 需要后续链接为空
                        cur->next = nullptr;
                    }else{
                        cur->next = slow;
                        cur = cur->next;
                        // 易错点1: 需要后续链接为空
                        cur->next = nullptr;
                    }
                }
                slow = quick;
                flag = true;
            }
            quick = quick->next;
        }
        // 易错点2: 考虑最后的slow节点
        if(flag && result != nullptr) cur->next = slow;
        // 易错点3: 考虑最后的slow节且res为空的情况
        if(flag && result == nullptr) result = slow;
        return result;
    }
};
// @lc code=end

