/*
 * @Date: 2023-05-10 15:02:06
 * @LastEditTime: 2023-05-10 19:28:59
 * @题目描述: 实现一个LFU缓存, 排除最近最少使用的项, 要求get和put都是O(1)的复杂度
 * @思路解法: 每次在使用put和get的过程中, 某个key的值就会+1, 如果在满了的情况下, 就需要删除freq相同的最久的那个key
 * @优化思路: 使用一个哈希表来存储key和val直接的对应关系, 使用一个哈希表来存储key和freq的对应关系, 使用一个哈希表来存储, freq和key链表的对应关系
 * @关键算法: O(1)找到freq最小最久的: 使用一个minFreq, 找到最少的频次, freq-key表中使用双向链表来方便的插入删除节点, 以及找到最早的节点
 * @复杂度: O(1)
 * @边界条件: 
 * @相似题目: 146
 */
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class DoubleLinkedNode{
    struct Node
    {
        Node* prev, *next;
        int key;
        Node(int key): prev(nullptr), next(nullptr){}
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
        node->prev = node->next;
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
        end->prev->next = node;
        node->prev = end->prev;
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
            DoubleLinkedNode* dlist2;
            dlist2->AddKey(key);
            freqToKey[1] = dlist2;
            return;
        }
        DoubleLinkedNode* dlist3 = freqToKey[1];
        dlist3->AddKey(key);
    }
};
