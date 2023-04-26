#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) { // 注意 while 处理多个 case
        vector<string> str;
        string p = s + '.';
        int h = 0;
        for(int i = 0; i < p.size(); i++){
            if(p[i] == '.'){
                str.push_back(p.substr(h, i - h));
                h = i + 1;
            }
        }
        if(str.size() != 4){
            cout<<"NO";
            return 0;
        }
        for(int i = 0; i < 4; i++){
            if(!regex_match(str[i], regex("[1-9][0-9]*|0"))){
                cout<<"NO";
                return 0;
            }
        }
        int a(256),b(256),c(256),d(256);
        sscanf(s.c_str(), "%u.%u.%u.%u", &a,&b,&c,&d);
        bool flag1 = a < 256?true: false;
        bool flag2 = b < 256?true: false;
        bool flag3 = c < 256?true: false;
        bool flag4 = d < 256?true: false;
        cout<< (flag1 && flag2 && flag3 && flag4 ? "YES":"NO");
    }
    return 0;
}
// 64 位输出请用 printf("%lld")