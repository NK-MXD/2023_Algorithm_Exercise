#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    string s;
    vector<int> mom;
    int a, b, p;
    while (cin >> s) { // 注意 while 处理多个 case
        mom.clear();
        sscanf(s.c_str(), "%d/%d", &a, &b);
        while(b % a != 0){
            p = b / a + 1;
            a = a - b%a;
            b = b*p;
            mom.push_back(p);
        }
        mom.push_back(b/a);
        int i = 0;
        for(;i < mom.size() - 1; i++){
            cout<<"1/"<<mom[i]<<"+";
        }
        cout<<"1/"<<mom[i]<<endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")