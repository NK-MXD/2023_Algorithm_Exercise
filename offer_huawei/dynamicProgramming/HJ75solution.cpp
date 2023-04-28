#include <iostream>
#include<string>
#include<vector>
using namespace std;

// 最长公共子序列
vector<vector<int>> memo;
// 定义：计算 s1[i..] 和 s2[j..] 的最长公共子序列长度
int dp(string s1, int i, string s2, int j) {
    // base case
    if (i == s1.length() || j == s2.length()) {
        return 0;
    }
    // 如果之前计算过，则直接返回备忘录中的答案
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    // 根据 s1[i] 和 s2[j] 的情况做选择
    if (s1[i] == s2[j]) {
        // s1[i] 和 s2[j] 必然在 lcs 中
        memo[i][j] = 1 + dp(s1, i + 1, s2, j + 1);
    } else {
        // s1[i] 和 s2[j] 至少有一个不在 lcs 中
        memo[i][j] = max(
            dp(s1, i + 1, s2, j),
            dp(s1, i, s2, j + 1)
        );
    }
    return memo[i][j];
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) { // 注意 while 处理多个 case
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> tb(n + 1, vector<int>(m + 1, 0));
        vector<int> temp(m, -1);
        memo.resize(n, temp);
        // base case为0;
        int length = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m;j++){
                if(s1[i - 1] == s2[j - 1]){
                    tb[i][j] = tb[i-1][j-1] + 1;
                    if(tb[i][j] > length) length = tb[i][j];
                }
                // else{
                //     tb[i][j] = max(tb[i][j - 1], tb[i - 1][j]);
                // }
            }
        }
        cout<<length;
        // cout<<dp(s1, 0, s2, 0);
    }
}
// 64 位输出请用 printf("%lld")