#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    // ip地址转化为2进制数拼接再转化为10进制:
        // 10>>24 + 0 >> 16 + 3 >> 8 + 193
    // 10进制数转化为ip地址:
        // 167773121 << 24 : << 16 && OxFF : << 8 && OxFF : && OxFF
    string ipstr;
    long dec;
    cin >> ipstr >> dec;
    // 字符串转化为数字:
    stringstream ipstream(ipstr);
    string temp;
    long res = 0;
    while(getline(ipstream, temp, '.')){
        res = res * 256 + atoi(temp.c_str());
    }
    cout<<res<<endl;
    
    vector<uint> res2;
    for(int i = 3; i >= 0 ; i--){
        res2.push_back((dec >> (i*8)) & 0xFF);
    }
    int i;
    for(i = 0; i < 3; i++){
        cout<<res2[i]<<".";
    }
    cout<<res2[i];
    return 0;
}