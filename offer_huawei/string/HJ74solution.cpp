#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string k;
    vector<string> res;
    while (getline(cin, k)) { // 注意 while 处理多个 case
        res.clear();
        string s = k + ' ';
        int left = 0;
        bool sign = false;
        for(int i =0; i < s.size();i++){
            if(sign){
                if(s[i] == '\"'){
                    res.push_back(s.substr(left, i - left));
                    sign = false;
                    left = i + 1;
                }
            }
            else{
                if(s[i] == ' '){
                    if(s[i-1]&&s[i-1]!=' '&&s[i-1]!='\"')
                        res.push_back(s.substr(left, i - left));
                    left = i + 1;
                }else if(s[i] == '\"'){
                    sign = true;
                    left = i + 1;
                }
            }
        }
        cout<<res.size()<<endl;
        for(auto ss: res){
            cout<<ss<<endl;
        }

    }
}
// 64 位输出请用 printf("%lld")