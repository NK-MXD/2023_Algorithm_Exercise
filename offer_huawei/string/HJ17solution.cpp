#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // 1. 字符串的分割
    // C++中用stringstream来实现
    string input;
    getline(cin, input); //输入整行字符串

    stringstream res(input);
    string temp;
    vector<string> tokens;

    while(getline(res, temp, ';')){
        tokens.push_back(temp);
    }
    // 2. 根据每一个token进行判断
    int first = 0, second = 0;
    for(int i = 0; i < tokens.size(); i++){
        string token = tokens[i];
        int j = 0;
        while(j < token.length() && token[j] == ' ') j++;
        if(j+3 < token.length() || j == token.length()) continue;
        string a = token.substr(j, 1);
        string num = token.substr(j+1, 2);

        // 3. 判断是否为两位数字, 也可以使用正则表达式来进行判断
        if(!regex_match(num, regex("[0-9]*"))){
            continue;
        }
        

        int digit = 0;
        sscanf(num.c_str(), "%d", &digit);

        switch (a[0])
        {
        case 'A': first -= digit;
            break;
        case 'D': first += digit;
            break;
        case 'S': second -= digit;
            break;
        case 'W': second += digit;
            break;
        default:
            break;
        }
    }

    cout<<first<<","<<second<<endl;
    return 0;
}