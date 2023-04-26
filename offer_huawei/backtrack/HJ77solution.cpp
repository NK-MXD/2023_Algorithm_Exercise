#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<int>&num,vector<int>& temp, vector<int>& res0, int i){
    if(res0.size() == num.size()){
        res.push_back(res0);
        return;
    }
    // 进站
    if(i < num.size()){
        temp.push_back(num[i]);
        backtrack(num, temp, res0, i + 1);
        temp.pop_back();
    }
    // 出站
    if(!temp.empty()){
        res0.push_back(temp.back());
        temp.pop_back();
        backtrack(num, temp, res0, i);
        temp.push_back(res0.back());
        res0.pop_back();
    }

}

int main() {
    int n;
    vector<int> trains, temp, res0;
    while (cin >> n) { // 注意 while 处理多个 case
        trains.resize(n);
        for(int i = 0; i < n;i++){
            cin>>trains[i];
        }
        // 使用递归算法进行遍历
        backtrack(trains, temp, res0, 0);
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size();i++){
            for(auto i: res[i]){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}
// 64 位输出请用 printf("%lld")