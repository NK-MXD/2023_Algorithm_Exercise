/*
 * @Date: 2023-05-10 10:38:30
 * @LastEditTime: 2023-05-10 19:45:09
 * @题目描述: 实现一个数据结构, 具有LRU缓存的功能, get和put都是O(1)的算法复杂度
 * @思路解法: 1. 每次取元素(最方便的是哈希表O(1))每次取用元素放元素(最方便的是双向队列O(1)) 2. 每次将元素打时间戳
 * @优化思路: 每次涉及到移动元素, 最方便的方法是使用链表, 使用双向链表和哈希表来实现功能
 * @关键算法: 双向哈希链表
 * @复杂度: O(1)
 * @边界条件: 链表的收尾节点为虚节点
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DoubleLinkedNode{
    struct Node
    {
        Node* prev, *next;
        int key;
        Node(int key_): key(key_), prev(nullptr), next(nullptr){}
    };
    Node* start, *end;
    unordered_map<int, Node*> map;
public:
    DoubleLinkedNode(){
        start = new Node(-1);
        end = new Node(-1);
        start->next = end;
        end->prev = start;
    }
    void Remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        map.erase(node->key);
        delete node;
    }
    Node* FindNode(int key){
        if(!map.count(key)){
            return nullptr;
        }
        return map[key];
    }
    void Remove(int key){
        Node* node = FindNode(key);
        if(node == nullptr){
            return;
        }
        Remove(node);
    }
    void AddKey(int key){
        Node *node = new Node(key);
        map[key] = node;
        AddNode(node);
    }
    void AddNode(Node* node){
        node->prev = end->prev;
        end->prev->next = node;
        node->next = end;
        end->prev = node;
    }
    bool empty(){
        return map.empty();
    }
    int RemoveFirst(){
        if(start->next == end) return -1;
        Node* node = start->next;
        int key = node->key;
        Remove(node);
        return key;
    }
};

class LFUCache {
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, DoubleLinkedNode*> freqToKey;
    int minFreq;
    int capacity;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = -1;
    }
    
    int get(int key) {
        if(!keyToVal.count(key)){
            return -1;
        }
        int freq = keyToFreq[key];
        DoubleLinkedNode* dlist = freqToKey[freq];
        dlist->Remove(key);
        // 更新minFreq
        if(minFreq == freq){
            if(dlist->empty()){
                minFreq++;
            }
        }
        if(!freqToKey.count(freq + 1)){
            DoubleLinkedNode* dlist2 = new DoubleLinkedNode();
            dlist2->AddKey(key);
            freqToKey[freq + 1] = dlist2;
            keyToFreq[key]++;
            return keyToVal[key];
        }
        DoubleLinkedNode *dlist3 = freqToKey[freq + 1];
        dlist3->AddKey(key);
        keyToFreq[key]++;
        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if(keyToVal.count(key)){
            keyToVal[key] = value;
            get(key);
            return;
        }
        if(keyToVal.size() == capacity){
            while(freqToKey.count(minFreq) == 0) minFreq++;
            DoubleLinkedNode* dlist = freqToKey[minFreq];
            int key = dlist->RemoveFirst();
            keyToFreq.erase(key);
            keyToVal.erase(key);  
            if(dlist->empty()){
                minFreq++;
            }
        }
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        if(minFreq > 1 || minFreq == -1){
            minFreq = 1;
        }
        if(!freqToKey.count(1)){
            DoubleLinkedNode* dlist2 = new DoubleLinkedNode();
            dlist2->AddKey(key);
            freqToKey[1] = dlist2;
            return;
        }
        DoubleLinkedNode* dlist3 = freqToKey[1];
        dlist3->AddKey(key);
    }
};