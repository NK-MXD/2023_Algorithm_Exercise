#include<iostream>
#include<vector>
#include<unordered_map>
#include<random>
using namespace std;

// 常数时间删除数组元素, 插入数组元素, 随机返回现有数组一项
// 插入: push_back
// 删除: 保存数组下标在哈希表当中, 置换与最后元素的位置, pop_back
// 随机返回
class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> map;
    default_random_engine gen{random_device{}()};
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(map.count(val)){
            return false;
        }
        map.insert({val, nums.size()});
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!map.count(val)){
            return false;
        }
        int temp = nums.back();
        nums[map[val]] = temp;
        nums.pop_back();
        map[temp] = map[val];
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int k = gen()%nums.size();
        return nums[k];
    }
};