#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 给定一个区间列表, 删除区间列表中被其它区间覆盖的区间, 返回剩余的区间数目
// 算法思路: 首先先将区间的首元素进行排序, 然后按照尾元素从大到小排序, 排序之后, 比较尾元素 
class Solution{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals){
        // 首先对首元素进行排序:
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                return a[1] > b[1];
            else 
                return false;
        });
        // 找到最大的元素, 进行区间覆盖
        int k = intervals[0][0];
        int count = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] > k){
                k = intervals[i][1];
                count++;
            }
            else{    
                continue;
            }
        }
        return count;
    }
};