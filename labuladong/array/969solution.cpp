#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 每次反转k前k个子串的数组, 直到数组变为有序的状态
// 算法思路: 可以发现每次都是翻转前面的数字, 一种可能的方法是先翻转使得最后的数字有效, 然后翻转剩下的数字
// 这是一个递归的算法思路
class Solution{
    vector<int> res;
public:
    vector<int> pancakeSort(vector<int>& arr){
        // 递归基
        if(arr.size() <= 1) return {};
        // 找到arr数组当中的最大的值对应的下标
        int n = arr.size();
        auto it = find(arr.begin(), arr.end(), n);
        int index = it - arr.begin();
        // 然后将对应的下标换到最后的位置, 所经历的翻转, 一次index + 1, 一次n
        vector<int> temp;
        temp.push_back(index + 1);
        temp.push_back(n);
        reverse(arr.begin(), it + 1);
        reverse(arr.begin(), arr.end());
        // 然后进行递归
        arr.pop_back();
        vector<int> temp2 = pancakeSort(arr);
        // 得到最后的结果
        for(auto i: temp2){
            temp.push_back(i);
        }
        return temp;
    }
};