/*
 * @Date: 2023-05-14 13:33:28
 * @LastEditTime: 2023-05-14 13:42:27
 * @题目描述: 有一个数组, 重新排列数组使得其中任意两个相邻元素不相等
 * @思路解法: 从1遍历, 每次遇到相同的就交换下一个元素, 但是当[2,1,1]这种情况, 重复元素都在后面的话就没有办法
 * @优化思路: 可以从前往后遍历一次, 再从后往前遍历一次, 保证都相邻元素都不相等
 * @关键算法: 
 * @复杂度: O(n^2)
 * @边界条件: 
 * @静态Debug易错点: swap之后要break
 * @相关题目: 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // sort(barcodes.begin(), barcodes.end());
        int n = barcodes.size();
        for(int i = 1; i < n; i++){
            if(barcodes[i] == barcodes[i - 1]){
                for(int j = i + 1; j < n; j++){
                    if(barcodes[j] != barcodes[i]){
                        swap(barcodes[i], barcodes[j]);
                        break;
                    }
                }
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(barcodes[i] == barcodes[i + 1]){
                for(int j = i - 1; j >= 0; j--){
                    if(barcodes[j] != barcodes[i]){
                        swap(barcodes[i], barcodes[j]);
                        break;
                    }
                }
            }
        }
        return barcodes;
    }
};