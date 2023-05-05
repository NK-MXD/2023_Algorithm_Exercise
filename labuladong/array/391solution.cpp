#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// 如果所有矩形组成的形状精确覆盖了矩形区域范围则返回true. 不能有重叠或者空隙的地方
// 算法思路: 第一种思路是判断面积(但是也不全面), 还需要判断恰好是矩形的四个顶点
class Solution{
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // 最终矩形的点(x1, y1) (x1, y2), (x2, y1), (x2, y2)
        int X1 = INT_MAX, Y1 = INT_MAX;
        int X2 = INT_MIN, Y2 = INT_MIN;
        // 理想矩形面积
        double area = 0;
        double real = 0;
        // 顶点集合: 注意一个矩形顶点重合为最后图形顶点, 2个为线段, 3个为顶点, 4个为点
        set<pair<int, int>> record; 
        for(auto rec: rectangles){
            int x1 = rec[0], y1 = rec[1];
            int x2 = rec[2], y2 = rec[3];
            X1 = min(x1, X1);
            Y1 = min(y1, Y1);
            X2 = max(x2, X2);
            Y2 = max(y2, Y2);
            real += (double)(x2 - x1)*(y2 - y1);
            pair<int, int> p1(x1, y1), p2(x1, y2), p3(x2, y1), p4(x2, y2);
            for(auto p: {p1, p2, p3, p4}){
                if(record.count(p)){
                    record.erase(p);
                }else{
                    record.insert(p);
                }
            }
        }
        area = (double)(X2 - X1)*(Y2 - Y1);
        if(area != real) return false;
        if(record.size() != 4) return false;
        pair<int, int> P1(X1, Y1), P2(X1, Y2), P3(X2, Y1), P4(X2, Y2);
        for(auto P: {P1,P2,P3,P4}){
            if(!record.count(P)){
                return false;
            }
        }
        return true;
    }
};