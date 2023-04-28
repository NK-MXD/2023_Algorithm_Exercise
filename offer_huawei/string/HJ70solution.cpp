#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    string s; // 计算规则
    while (cin >> n) { // 注意 while 处理多个 case
        vector<vector<int>> mat(n, vector<int>(2,0));
        for(int i = 0; i < n; i++){
            cin>>mat[i][0]>>mat[i][1];
        }
        // 下面计算计算量
        cin>>s;
        // 括号匹配
        vector<int> vec;
        int sum = 0;
        int p = 0, k = 0, q = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i] != ')'){
                if(s[i] == '(')
                    p++;
                else
                    vec.push_back(k++);
            }
            else{
                if(++q > p) break;
                int y = vec.back();
                vec.pop_back();
                int x = vec.back();
                vec.pop_back();
                sum += mat[x][0]*mat[x][1]*mat[y][1];
                mat[x][1] = mat[y][1];
                vec.push_back(x);
            }
        }
        cout<<sum<<endl;
    }
}
// 64 位输出请用 printf("%lld")