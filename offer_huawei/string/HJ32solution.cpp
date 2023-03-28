#include <iostream>
#include <string>
using namespace std;

int findparlindrome(string str, int i, int j){
    while(i >= 0 && j < str.length() && str[i] == str[j]){
        i--;
        j++;
    }
    return j - i - 1;
}

int main() {
    // 本题是求解最长的对称字符串(回文字符串)
    // 求解的思路: 从字符串的不同中心寻找回文字符串
    string str;
    int maxl = 0;
    while(cin>>str){
        for(int i = 0; i < str.length(); i++){
            int l1 = findparlindrome(str, i, i);
            int l2 = findparlindrome(str, i, i+1);
            maxl = maxl > max(l1, l2)? maxl: max(l1, l2);
        }
    }
    cout<<maxl;
    return 0;
}