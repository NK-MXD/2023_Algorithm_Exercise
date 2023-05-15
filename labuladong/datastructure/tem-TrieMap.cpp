/*
 * @Date: 2023-05-11 08:18:32
 * @LastEditTime: 2023-05-11 09:02:54
 * @题目描述: 这里是Trie树的实现, 键为string, 值的类型为V,
 * @思路解法: 
 * @优化思路: 
 * @关键算法: 
 * @复杂度: 
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<typename V>
class TrieMap{
    const int NumOfChar = 256;  // 引入ASCII码的个数
    int size = 0;  // Map当中的键值对的数量
    struct TrieNode<V>{
        V val = NULL;
        vector<TrieNode<V>> children(NumOfChar);
    };
    // Trie树的根节点
    TrieNode<V> root = NULL;

    // 从节点node开始搜索key, 如果存在返回对应的节点, 否则返回null
    TrieNode<V> getNode(TrieNode<V> node, string key){
        TrieNode<V> p = node;
        int length = key.length();
        for(int i = 0; i < length; i++){
            if(p == NULL){
                return NULL;
            }
            char c = key[i];
            p = p.children[i];
        }
        return p;
    }

    void traverse(TrieNode<V> node, vector<string> res, string path){
        if(node == NULL){
            return;
        }
        if(node.val != NULL){
            res.push_back(path);
        }
        for(char c = 0; c < NumOfChar; i++){
            path.append(c);
            traverse(node.children[c], res, path);
            path.pop_back();
        }
    }

    void traverse(TrieNode<V> node, string path, string pattern, int i, vector<string> res){
        if(node == NULL){
            return;
        }
        if(i == pattern.length()){
            if(node.val != NULL){
                res.push_back(path);
            }
            return;
        }
        char c = pattern[i];
        if(c == '.'){
            for(char j = 0; j < NumOfChar; j++){
                path.push_back(c);
                traverse(node.children[j], path, pattern, i + 1, res);
                path.pop_back();
            }
        }else{
            path.push_back(c);
            traverse(node.children[c], path, pattern, i + 1, res);
            path.pop_back();
        }
    }
    
public:
    // 增加key
    void put(string key, V val){

    }
    // 删除key
    void remove(string key){

    }

    // 搜索key
    V get(string key){
        // 从root开始搜索
        TrieNode<V> x = getNode(root, key);
        if(x == NULL || x.val == NULL){
            return NULL;  // 节点值为NULL说明为中间节点
        }
        return x.val;
    }

    // 判断key是否在map中
    bool containsKey(string key){
        return get(key) != NULL;
    }

    // 搜索query的最短前缀
    string shortestPrefixOf(string query){
        TreeNode<V> p = root;
        // 找第一次遇到值的前缀
        for(int i = 0; i < query.length(); i++){
            if(p == NULL){
                return "";
            }
            if(p.val != NULL){
                // 找到一个键是query的前缀
                return query.substr(0, i);
            }
            char c = query[i];
            p = p.children[c];
        }
        if(p != NULL && p.val != NULL){
            // query本身就是一个key
            return query;
        }
        return query;
    }

    // 搜索query的最长前缀
    string longestPrefixOf(string query){
        TreeNode<V> p = root;
        int max_len = 0;
        // 找第一次遇到值的前缀
        for(int i = 0; i < query.length(); i++){
            if(p == NULL){
                break;
            }
            if(p.val != NULL){
                // 找到一个键是query的前缀
                max_len = i;
            }
            char c = query[i];
            p = p.children[c];
        }
        if(p != NULL && p.val != NULL){
            // query本身就是一个key
            return query;
        }
        return query.substr(0, max_len);
    }

    // 搜索前缀为prefix的所有key
    vector<string> keysWithPrefix(string prefix){
        // 找到前缀所在的TrieTree当中的节点
        TrieNode<V> node = getNode(root, prefix);
        vector<TrieNode<V>> res;
        if(node == NULL){
            return res;
        }
        // DFS遍历以node为root的子树
        strings path = "";
        traverse(node, res, path);
        return res;
    }
    
    // 判断是否存在前缀为prefix的key
    bool hasKeyWithPrefix(string prefix){
        // 前缀在TrieTree当中
        return getNode(root, prefix) != NULL;
    }

    // 通配符.匹配任意字符, 搜索所有匹配的键
    vector<string> keysWithPattern(string pattern){
        vector<string> res;
        string path = "";
        traverse(root, path, pattern, 0, res);
    }

    // 通配符.判断是否存在任意字符
    bool hasKeyWithPattern(string pattern){
        
    }

    // 返回Map当中的键值对数量
    int size(){

    }
};
