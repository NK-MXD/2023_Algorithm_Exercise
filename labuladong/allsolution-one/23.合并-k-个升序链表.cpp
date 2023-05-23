/*
 * @Date: 2023-05-18 12:33:42
 * @LastEditTime: 2023-05-18 12:53:42
 * @题目描述: 
 * @思路解法: 想到的想法是先将所有的第一个元素都加入小根堆里, 然后每次找最小的node, 将它下一个node加入小根堆中
 * @优化思路: 
 * @关键算法: 小根堆, 堆算法
 * @复杂度: O(nlogn)
 * @边界条件: 
 * @静态Debug易错点: 小根堆用#include<queue> 注意其中为空的节点不要添加进入堆中
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
// #include<queue>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
private:
    struct compare{
        bool operator() (ListNode* node1, ListNode* node2){
            return node1->val > node2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int n = lists.size();
        for(ListNode *node: lists){
            if(node)
                pq.push(node);
        }
        while(!pq.empty()){
            ListNode* cur = pq.top();
            pq.pop();
            p->next = cur;
            ListNode* temp = cur->next;
            cur->next = nullptr;
            if(temp != nullptr)
                pq.push(temp);
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

