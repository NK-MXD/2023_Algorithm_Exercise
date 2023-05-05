#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 将所有重叠的区间进行合并, 并返回合并后的最终的区间
// 相似题目: 1288
// 算法思想: 先进行排序
class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] > b[1];
            else
                return false;
        });
        // 然后进行合并区间
        int left = intervals[0][0];
        int right = intervals[0][1];
        // 结果区间
        vector<vector<int>> res;
        for(int i = 1; i < intervals.size(); i++){
            int nl = intervals[i][0], nr = intervals[i][1];
            if(nl <= right){
                right = max(right, nr);
            }
            else{
                res.push_back({left, right});
                left = nl;
                right = nr;
            }
        }
        res.push_back({left, right});
        return res;
    }
};