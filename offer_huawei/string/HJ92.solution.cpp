#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    while (cin >> s) { // 注意 while 处理多个 case
        vector<string> res;
        int length = 0;
        int left = 0;
        int i = 0;
        int temp = 0;
        while(i < s.length()){
            if(s[i] >= '0'&&s[i] <= '9'){
                temp++;
                if(temp > length){
                    res.clear();
                    length = temp;
                    res.push_back(s.substr(left, temp));
                }
                else if(temp == length){
                    res.push_back(s.substr(left, temp));
                }
            }else{
                left = i + 1;
                temp = 0;
            }
            i++;
        }
        for(auto k: res){
            cout<<k;
        }
        cout<<","<<res[0].length()<<endl;
    }
}