#include<iostream>
#include<vector>
#include<random>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 求解从链表中随机选择一个节点, 时间复杂度为O(n)
// 算法思路: 遍历时按照1/i的概率取用该元素, 1-1/i的概率不取用该元素
class Solution {
    default_random_engine gen{random_device{}()};
    ListNode* root;
public:
    Solution(ListNode* head) {
        root = head;
    }
    int getRandom() {
        ListNode* temp = root;
        int res = root->val;
        int i = 0;
        while(temp!=nullptr){
            // uniform_int_distribution<int> dis(0, i);
            i++;
            if(gen()%i == 0){
                res = temp->val;
            }
            temp = temp->next;
        }
        return res;
    }
};