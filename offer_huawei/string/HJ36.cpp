#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 输入的是key和要加密的字符串, 输入字符串全部为小写
    // 输出为加密后的字符串
    string key, input;
    string output("");
    vector<char> all;
    set<char> alpha;
    vector<char> secret;
    for(char a = 'a'; a <= 'z'; a++){
        all.push_back(a);
    }
    while (cin >> key >> input) { // 注意 while 处理多个 case
        // 构建密码本
        for(int i = 0; i < key.size(); i++){
            if(alpha.count(key[i]) == 0){
                alpha.insert(key[i]);
                secret.push_back(key[i]);
            }
        }
        for(int i = 0; i < all.size(); i++){
            if(alpha.count(all[i]) == 0){
                secret.push_back(all[i]);
            }
        }
        // 翻译明文
        for(int i = 0; i < input.size(); i++){
            output += secret[input[i] - 'a'];
        }
    }
    cout<<output;
    return 0;
}
// 64 位输出请用 printf("%lld")