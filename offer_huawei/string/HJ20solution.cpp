#include <iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. 长度超过八位
    string input;
    while(getline(cin, input)){
        bool istrue = true;
        if(input.length() <= 8){
            cout<<"NG"<<endl;
            continue;
        }
        int flag = 0;
        // 2. 大小写字母, 数字, 其它符号
        // 打算使用正则表达式
        if(regex_search(input, regex("[0-9]+"))){
            flag++;
        }
        if(regex_search(input, regex("[a-z]+"))){
            flag++;
        }
        if(regex_search(input, regex("[A-Z]+"))){
           
            flag++;
        }
        if(regex_search(input, regex("[^0-9^a-z^A-Z^ ^\\n]+"))){
            flag++;
        }
        if(flag < 3){
            cout<<"NG"<<endl;
            continue;
        }
        // 3. 长度大于2的包含公共元素的子串重复
        for(int i = 0; i < input.length()-2; i++){
            string sub = input.substr(i, 3);
            string next = input.substr(i+1, input.length());
            if(next.find(sub) != next.npos){
                istrue = false;
                break;
            }
        }
        if(istrue) cout<<"OK"<<endl;
        else cout<<"NG"<<endl;
    }
    return 0;
}
