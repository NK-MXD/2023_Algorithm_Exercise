#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 最简单的思路: 一个unordered_map
// 优化思路: 一个数和它本身的异或为0, 只需要将所有数都进行异或
class Solution{
    unordered_map<int, int> map;
public:
    int singleNumber(vector<int>& nums) {
        for(auto i: nums){
            if(map[i] == 0){
                map[i] = 1;
            }else if(map[i] == 1){
                map[i] = 0;
            }
        }
        for(auto i: map){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
    }   
    int singleNumber2(vector<int>& nums){
        int res = 0;
        for(auto i: nums){
            res ^= i;
        }
        return res;
    }
};