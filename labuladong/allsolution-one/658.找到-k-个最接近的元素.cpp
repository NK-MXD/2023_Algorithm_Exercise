/*
 * @Date: 2023-05-23 17:57:46
 * @LastEditTime: 2023-05-23 21:25:08
 * @题目描述: 
 * @思路解法: 先使用二分搜索找到x元素的位置, 然后使用类似回文数组判定的方式从两端向中间判定最接近的k个元素
 * @优化思路: 还可以直接使用sort排序
 * @关键算法: 
 * @复杂度: O(log2n) + O(n)
 * @边界条件: 
 * @静态Debug易错点: 
 * @相关题目: 
 */
/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
    int findElement(vector<int>& arr, int target){
        int n = arr.size();
        int left = 0, right = n;
        int mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(arr[mid] < target){
                left = mid + 1;
            }else if(arr[mid] > target){
                right = mid;
            }else{
                right = mid;
            }
        }
        return left;
    }
public:
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     // 首先找到左侧边界, 从左侧边界开始向左向右扩展
    //     int leftboard = findElement(arr, x);
    //     vector<int> res;
    //     int left = leftboard - 1, right = leftboard;
    //     while(res.size() < k){
    //         if(left == -1){
    //             res.push_back(arr[right]);
    //             right++;
    //         }else if(right == arr.size()){
    //             res.insert(res.begin(), arr[left]);
    //             left--;
    //         }else if(x - arr[left] > arr[right] - x){
    //             res.push_back(arr[right]);
    //             right++;
    //         }else{
    //             res.insert(res.begin(), arr[left]);
    //             left--;
    //         }
    //     }
    //     // sort(res.begin(), res.end());
    //     return res;
    // }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](int &a, int &b){
            if(abs(a - x) < abs(b - x)) return true;
            else if(abs(a - x) == abs(b - x)) return a < b;
            return false;
        });
        vector<int> res;
        for(int i = 0; i < arr.size() && i < k; i++){
            res.push_back(arr[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

