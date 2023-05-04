#include<iostream>
#include<vector>
using namespace std;

// 计算阶乘后末尾恰好含有k个零的阶乘的数的个数
// 已知有k个5, 现在要计算满足k个5的元素的个数
// 其中一种算法: 在区间[0, LONG_MAX]区间内, 寻找末尾为k个零的阶乘的数
// 优化算法: 一种缩小范围的方式
class Solution{
    // 计算n的末尾为k个零
    long tailingZeroes(long k){
        long res = 0;
        while(k != 0){
            res += k / 5;
            k /= 5;
        }
        return res;
    }
    
    long left_bound(int target){
        long left = target << 1;
        long right = long(target + 1) << 3;
        long mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(tailingZeroes(mid) < target){
                left = mid + 1;
            }else if(tailingZeroes(mid) > target){
                right = mid;
            }else{
                right = mid;
            }
        }
        return left;
    }

    long right_bound(int target){
        long left = target << 1;
        long right = long(target + 1) << 3;
        long mid;
        while(left < right){
            mid = left + (right - left) / 2;
            if(tailingZeroes(mid) < target){
                left = mid + 1;
            }else if(tailingZeroes(mid) > target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left - 1;
    }
public:
    int preimageSizeFZF(int K){
        // 这里采用二分搜索的策略
        return int(right_bound(K) - left_bound(K) + 1);
    }
};