#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isbrother(string str1, string str2){
    if(str1 == str2) return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    // 解题思路: 1. 将给定单词的兄弟单词找出来 2. 将给定的兄弟单词进行字典序排序 3. 找到第k个单词
    // 可以采用的方法: 根据给定的字典中的单词, 来判断该单词是否为给定单词的兄弟单词
    // 即给单词是否为给定单词的排列: 排序后查看是否相同
    int N;
    cin >> N;
    vector<string> dict(N);
    for(int i = 0; i < N; i++){
        cin >> dict[i];
    }
    string origin;
    int k;
    cin>>origin>>k;
    sort(dict.begin(), dict.end());//提前排序
    int sum = 0;
    string res;
    for(int i = 0; i < dict.size(); i++){
        if(isbrother(dict[i], origin)){
            sum++;
            if(sum == k)
                res = dict[i];
        }
    }
    cout<<sum<<endl<<res;
    return 0;
}
