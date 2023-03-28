#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isA(char a){
    if(a >= 'A' && a <= 'Z')
        return true;
    return false;;
}

bool isa(char a){
    if(a >= 'a' && a <= 'z')
        return true;
    return false;;
}

int main() {
    // 加密字母的变换法则 A 65 a 97 计算方式: 
        // 小写字母(n - 97 + 1)%26 + 65, 注意26一循环
        // 大写字母(n - 65 + 1)%26 + 97, 注意26一循环
    // 加密数字的变换法则 (n - 47)%10 + 48

    // 解密字母的变换法则 A 65 a 97 计算方式: 
        // 小写字母(n - 97 + 25)%26 + 65, 注意26一循环
        // 大写字母(n - 65 + 25)%26 + 97, 注意26一循环
    // 解密数字的变换法则 (n - 39)%10 + 48
    string str1, str2;
    cin >> str1 >> str2;
    vector<char> res(str1.length()), res2(str2.length());
    for(int i = 0; i < str1.length(); i++){
        if(isA(str1[i])) res[i] = (str1[i] - 65 + 1)%26 + 97;
        else if(isa(str1[i])) res[i] = (str1[i] - 97 + 1)%26 + 65;
        else if(isdigit(str1[i])) res[i] = (str1[i] - 47)%10 + 48;
    }
    for(int i = 0; i < str2.length(); i++){
        if(isA(str2[i])) res2[i] = (str2[i] - 65 + 25)%26 + 97;
        else if(isa(str2[i])) res2[i] = (str2[i] - 97 + 25)%26 + 65;
        else if(isdigit(str2[i])) res2[i] = (str2[i] - 39)%10 + 48;
    }
    for(int i = 0; i < res.size(); i++){
        cout<<res[i];
    }
    cout<<endl;
    for(int i = 0; i < res2.size(); i++){
        cout<<res2[i];
    }
    return 0;
}