#include<iostream>
#include<vector>
#include<unordered_map>
#include<random>
#include<algorithm>
using namespace std;

// 随机返回不在黑名单的整数
// 算法思路: 一种算法的思路是将所有的数字都push_back进入数组, 然后再生成对应的下标
// 优化算法思路: 就是将0-n看做一个数组, 对应的黑名单的数就是和已有的数组中的元素进行交换得到的结果
class Solution {
    // 将对应的黑名单中的数和数组最后的元素进行交换
    unordered_map<int, int> map;
    int N;
    default_random_engine gen{random_device{}()};
public:
    Solution(int n, vector<int>& blacklist) {
        N = n - blacklist.size();
        // 将黑名单中的数进行映射, 如果最后的元素本身就是黑名单中的值的话就无需映射
        int last = n - 1;
        sort(blacklist.rbegin(), blacklist.rend());
        for(auto i: blacklist){
            if(i >= N){
                map[i] = 666;// 这里做一个标记
                continue; 
            }// 因为不会选到大于等于N的数
            while(map[last]) last--;
            map[i] = last--; // 如果选到的话
        }
    }
    int pick() {
        int k = gen()%N;
        if(map[k]) return map[k];
        return k;
    }
};