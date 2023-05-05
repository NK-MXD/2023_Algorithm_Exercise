#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

// 最少添加的括号数目使得括号字符串有效
// 相关题目: 第20题, 第921题
// 算法思路: 用栈, 就是每次左括号换为了对应两个连续的右括号
// 注意: 每次左括号对应不上足够的右括号时添加2*左个括号. 每次右括号对应不上足够的左括号时,
// 偶数选择添加/2个左括号, 奇数选择添加/2 个左括号, 1个右括号
// 优化算法思路: 发现每次右括号匹配完毕都需要重新更新栈, 不如拿一个数字来动态维护
// 问题: 为什么该算法不会影响"())))("
class Solution{
public:
    int minInsertions(string s) {
        int res = 0, need = 0;
        // 其中res记录的是插入的括号数目, need代表对右括号的需求数目
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                need += 2;
                if (need % 2 == 1) {
                    res++;
                    need--;
                }
            }

            if (s[i] == ')') {
                need--;
                if (need == -1) {
                    res++;
                    need = 1;
                }
            }
        }
    
        return res + need;
    }
};