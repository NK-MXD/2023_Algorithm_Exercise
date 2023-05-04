#include<iostream>
#include<vector>
using namespace std;

// 解数独问题
// 算法: backtrack回溯算法
// 思路: 1. 对于每一个i,j选取1-9的数字进行遍历, 1-9的数字合法
//          进行下一次backtrack结束, 穷举每一列
//          base case是遍历到最后
class Solution{
private:
    bool valid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == ch){
                return false;
            }
            if(board[row][i] == ch){
                return false;
            }
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == ch){
                return false;
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board, int i, int j){
        int n = board.size(), m = board[0].size();
        if(j == m){
            return backtrack(board, i+1, j);
        }
        if(i == n){
            return true;
        }
        for(char ch = '1'; ch <= '9'; ch++){
            if(!valid(board, i, j, ch)){
                continue;
            }
            board[i][j] = ch;
            if(backtrack(board, i, j + 1)){
                return true;
            }
            board[i][j] = '.';
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board){
        backtrack(board, 0, 0);
    }
};