#include <iostream>
#include <string>
#include <vector>
using namespace std;

int match_string(string m_str, string w_str){
    int m_len = m_str.size();
    int w_len = w_str.size();
    vector<vector<int>> tb(w_len + 1, vector<int>(m_len + 1, 0));
    tb[0][0] = 1;
    for(int i = 1; i <= w_len; i++){
        char ch = w_str[i - 1];
        tb[i][0] = tb[i-1][0] && (ch == '*');
        for(int j = 1; j <= m_len; j++){
            char ch2 = m_str[j-1];
            if(ch == '*'){
                tb[i][j] = tb [i - 1][j] || tb[i][j-1];
            }else{
                if(ch == '?')
                    tb[i][j] = tb[i - 1][j - 1] && (isdigit(ch2) || isalpha(ch2) || ch2 == '.');
                else{
                    if(isalpha(ch2)){
                        tb[i][j] = tb[i-1][j-1] && (tolower(ch2) == tolower(ch));
                    }
                    else{
                        tb[i][j] = tb[i-1][j-1] && ch2 == ch;
                    }
                }
            }
        }
    }
    return tb[w_len][m_len];
}

int main() {
    string a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        int rst =  match_string(b,a);
        if(rst==1)
           cout << "true" << endl;
        else
           cout << "false" << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")