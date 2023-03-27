#include <iostream>
#include <vector>
using namespace std;

// 本题在原本动态规划的基础上添加了一个变量q, 表示是否可用;
// 某一物品q[i]为k,只有先购买对应的k物体才能购买i
int main() {
    int N, m;
    //N: 总钱数 m: 可以购买的物体个数
    cin >> N >> m;
    N = N / 10;
    //灵活使用10的倍数的条件
    vector<int> v(m, 0), p(m, 0), q(m, 0);
    //v: 表示花费, p: 表示重要程度 q: 表示所属物品
    for (int i = 0; i < m; i++) {
        cin >> v[i] >> p[i] >> q[i];
    }
    //需要将对应的附件放到主键的位置上
    vector<vector<int>> object(m, vector<int>(3, 0));
    vector<vector<int>> proprity(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++) {
        object[i][0] = v[i] / 10;
        proprity[i][0] = p[i];
        if (q[i] != 0) {
            if (object[q[i] - 1][1] == 0) {
                object[q[i] - 1][1] = v[i] / 10;
                proprity[q[i] - 1][1] = p[i];
            } else {
                object[q[i] - 1][2] = v[i] / 10;
                proprity[q[i] - 1][2] = p[i];
            }
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(N+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= N; j++) {
            if (q[i-1] == 0) {
                dp[i][j] = j - object[i - 1][0] >= 0 ? 
                    max(dp[i - 1][j - object[i - 1][0]] + proprity[i - 1][0] * object[i - 1][0], dp[i - 1][j]) 
                : dp[i - 1][j];

                dp[i][j] = j - object[i - 1][0] - object[i - 1][1] >= 0 ? 
                    max(dp[i - 1][j - object[i - 1][0] - object[i - 1][1]] + proprity[i - 1][0] * object[i - 1][0] + proprity[i - 1][1] *object[i - 1][1], 
                    dp[i][j]) 
                : dp[i][j];

                dp[i][j] = j - object[i - 1][0] - object[i - 1][2] >= 0 ? 
                    max(dp[i - 1][j - object[i - 1][0] - object[i - 1][2]] + proprity[i - 1][0] * object[i - 1][0] + proprity[i - 1][2] *object[i - 1][2], 
                    dp[i][j])
                : dp[i][j];

                dp[i][j] = j - object[i - 1][0] - object[i - 1][1] - object[i - 1][2] >= 0 ? 
                    max(dp[i - 1][j - object[i - 1][0] - object[i - 1][1] - object[i - 1][2]] + proprity[i - 1][0] * object[i - 1][0] + proprity[i - 1][1] *object[i - 1][1] + proprity[i - 1][2] * object[i - 1][2], 
                    dp[i][j]) 
                : dp[i][j];

            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    std::cout << dp[m][N] * 10;
    return 0;
}