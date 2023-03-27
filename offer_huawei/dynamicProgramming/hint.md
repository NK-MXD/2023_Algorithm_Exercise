# 这里是动态规划类型题目的思路框架

> 参考鸣谢   
> https://labuladong.github.io/algo/di-er-zhan-a01c6/bei-bao-le-34bd4/jing-dian--28f3c/

## 经典问题: 0-1背包问题

提供一个可装载重量为 W 的背包和 N 个物品，每个物品有重量和价值两个属性。其中第 i 个物品的重量为 wt[i]，价值为 val[i]，现在让你用这个背包装物品，最多能装的价值是多少？

动态规划的套路: 

1. 确定状态和选择: 状态就是背包的容量, 选择就是装或者不装五瓶;
2. 明确dp数组的定义: 比如说dp[i][w]的含义: 对于前i个物品, 当前背包容量为w, 能够装下的最大价值为dp[i][w], 那么对应的0-1背包问题最终要解决的问题就是dp[N-1][0]为多少?
3. 确定状态转移方程: dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]]+val[i-1])

根据上面的套路就可以总结出一下代码:

```c
int knapsack(int W, int N, int wt[], int val[]){
    int dp[N+1][W+1];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <=W; j++){
            if(j -wt[i-1] < 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = std::max(
                    dp[i-1][w],
                    dp[i-1][w - wt[i-1]] + val[i-1]
                );
            }
        }
    }
    return dp[N][W];
}
```

变式题目: HJ16 

尝试解法如下所示: 
```c
// 本题在原本动态规划的基础上添加了一个变量q, 表示是否可用;
// 某一物品q[i]为k,只有先购买对应的k物体才能购买i
int main() {
    int N, m;
    //N: 总钱数 m: 可以购买的物体个数
    cin >> N >> m;
    vector<int> v(m,0),p(m,0),q(m,0);
    //v: 表示花费, p: 表示重要程度 q: 表示所属物品
    for (int i = 0; i < m; i++) {
        cin >> v[i] >> p[i] >> q[i];
    }
    int **dp = new int*[m+1];
    int k[m];
    for(int i = 0; i <= m; i++){
        dp[i] = new int[N+1]{0};
        k[i] = q[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= N; j++){
            if(j - v[i-1] < 0 || k[i-1] != 0){
                dp[i][j] = dp[i-1][j];
            }else{
                if(dp[i-1][j-v[i-1]] + p[i-1]*v[i-1] < dp[i-1][j]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j-v[i-1]] + p[i-1]*v[i-1];
                    // 对于不同的j选择也不同
                    for(int h = 0; h < m; h++){
                        if(q[h] == i) k[h] = 0;
                    }
                }   
            }
        }
        // 不能这样子做的原因在于需要进行回溯, 可以排个序;
        // 但是排序的话又会打乱原本的存储在q里面的内容
        for(int h = 0; h < m; h++){
            k[h] = q[h];
        }
    }
    std::cout<<dp[m][N];
    return 0;
}
```

这种解法可以处理下面这种情况:

```
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
```

但是无法处理这种情况:

```
50 5
20 3 5
20 3 5
10 3 0
10 2 0
10 1 0
```

另外一种方法是将附件看做是主件的一部分, 动态规划只规划主件, 然后将对应的附件作为主件的一部分, 可以选择添加也可以选择不添加.



