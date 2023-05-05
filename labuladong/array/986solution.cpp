#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 求解两个区间列表的交集
// 相似题目: 1288, 56
// 算法思想: 两个区间本身自己是没有重叠区间的, 因此, 可以将两个区间合并看待, 其中的重叠的区间必然为两个区间彼此重叠的区间
class Solution{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList){
        vector<vector<int>> all(firstList.size() + secondList.size());
        copy(firstList.begin(), firstList.end(), all.begin());
        copy(secondList.begin(), secondList.end(), all.begin() + firstList.size());
        sort(all.begin(), all.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] < b[1];
            else
                return false;
        });
        // 然后找到其中区间的交集
        int left = all[0][0];
        int right = all[0][1];
        // 结果区间
        vector<vector<int>> res;
        for(int i = 1; i < all.size(); i++){
            int nl = all[i][0], nr = all[i][1];
            if(nl <= right){
                res.push_back({nl, min(right, nr)});
            }
            left = nl;
            // 注意这里的变换, 保留最大的right的值
            right = max(right, nr);
        }
        return res;
    }
};