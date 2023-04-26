#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    // 找到最大递增子序列
    while (cin >> a) { // 注意 while 处理多个 case
        vector<int> nums;
        for(int i = 0; i < a; i++){
            cin >> b;
            nums.push_back(b);
        }
        // 进行动态规划算法
        vector<int> tb(a, 1);
        for(int i = 0; i < a; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    tb[i] = max(tb[i], tb[j] + 1);
            }
        }
        int res;
        for(int i = 0; i < a; i++){
            res = max(res, tb[i]);
            // cout<<tb[i];
        }
        cout<<res;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")