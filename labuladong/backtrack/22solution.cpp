#include<iostream>
#include<vector>
using namespace std;

// 括号生成
// 算法: backtrack
// 思路: 相当于有n个位置, 每个位置可以放置(或者), 只需要在执行过程中进行剪枝即可
//       剪枝的思路: 之前是使用i来标识backtrack的位置, 剪枝的话可以使用left和right来标识
class Solution{
private:
    vector<string> res;
    void backtrack(string& s, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(s);
        }
        if(left > right || left < 0 || right < 0){
            return;
        }
        s.push_back('(');
        backtrack(s, left - 1, right);
        s.pop_back();
        s.push_back(')');
        backtrack(s, left, right - 1);
        s.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string str;
        int left = n, right = n;
        backtrack(str, left, right);
        return res;
    }
};

