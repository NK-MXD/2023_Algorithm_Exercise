#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// 通过符号c将字符串分割为两个部分
// 特殊符号: ! @ # + .
vector<string> split(string str, char c){
    if(c == '+'){
        // 只有一个+
        auto it = find(str.begin(), str.end(), c);
        int i = it - str.begin();
        string str1 = str.substr(0, i);
        string str2 = str.substr(i+1);
        return {str1, str2};
    }
    return {};
}

void process(vector<string>& vec){
    int n = vec[0].size(), m = vec[1].size();
    int left = n, right = m;
    for(int i = 0; i < n; i++){
        if(!isdigit(vec[0][i])){
            left = i;
            break;
        }
    }
    for(int i = 0; i < m; i++){
        if(!isdigit(vec[1][i])){
            right = i;
            break;
        }
    }
    // cout<<right<<left;
    while(left < right){
        vec[0].insert(vec[0].begin(),'0');
        left++;
    }
    while(right < left){
        vec[1].insert(vec[1].begin(),'0');
        right++;
    }
}

int cal(char a, char b){
    if(isdigit(a) && isdigit(b)){
        int int_a = a - '0';
        int int_b = b - '0';
        return int_a + int_b;
    }else if(a == '!' && b == '!'){
        return 0;
    }else if(a == '!' && b == '@'){
        return 13;
    }else if(a == '@' && b == '!'){
        return 13;
    }else if(a == '!' && b == '#'){
        return 4;
    }else if(a == '#' && b == '!'){
        return 4;
    }else if(a == '@' && b == '@'){
        return 7;
    }else if(a == '@' && b == '#'){
        return 20;
    }else if(a == '#' && b == '@'){
        return 20;
    }else if(a == '#' && b == '#'){
        return 5;
    }else if(a == '.' && b == '.'){
        return -1;
    }else{
        return -2;
    }
    
}

// 输入: 15 123.45#1+126.53@
// 7 1#3+1#0.4
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    // 首先可以将字符串分为两个加法部分
    vector<string> twopart = split(str, '+');
    // cout<<twopart[0]<<" "<<twopart[1];
    // 每个部分之间如何进行运算? 
    // 首先将两个字符串对齐, 以长字符串为标准, 从右到左进行计算
    // 对齐: 对齐的是首个特殊符号
    // 先处理字符串, 通过首位添零, 让首位对齐
    process(twopart);
    // for(auto str: twopart){
    //     cout<<str<<endl;
    // }
    // 长的那一部分直接放下来
    int max_len, max_i, min_len, min_i;
    if(twopart[0].size() > twopart[1].size()){
        max_len = twopart[0].size();
        max_i = 0;
        min_len = twopart[1].size();
        min_i = 1;
    }else{
        max_len = twopart[1].size();
        max_i = 1;
        min_len = twopart[0].size();
        min_i = 0;
    }
    vector<char> result(max_len + 1, '0');//可能会有进位
    vector<bool> flag(max_len + 1, true);
    vector<int> result_int(max_len + 1, 0);//可能会有进位
    int index = 0;
    while(max_len > min_len){
        result[max_len] = twopart[max_i][max_len - 1];
        index++;
        max_len--;
    }
    // 下面开始运算, 从末尾开始运算, 每次取一个字母进行运算
    // 当前位的值
    int temp = 0;
    // 进位的值
    int add = 0;
    while(min_len > 0){
        char left = twopart[min_i][min_len - 1];
        char right = twopart[max_i][min_len - 1];
        int res = cal(left, right); // 计算得到
        if(res == -1){
            // 说明为小数, 此时进的位加在上一位
            result[min_len] = '.';
        }else{
            // 注意result为char数组
            // 这是先加之前的进位
            result_int[min_len] += add;
            res = res + result_int[min_len];
            temp = res % 10;
            result_int[min_len] = temp;
            // 更新结果数组
            result[min_len] = temp + '0';
            // 更新下一位的进位的值
            add = res / 10;
        }
        min_len--;
    }
    result[0] = add + '0';
    
    bool flag2 = true;
    for(int i = 0; i < result.size(); i++){
        // 注意如果下一位为.的话就保留这一位的0
        if(flag2 && result[i] == '0' && (i + 1 < result.size() && result[i + 1] != '.')){
            flag2 = true;
            flag[i] = false;
            continue;
        }else if(flag2 && result[i] != '0'){
            flag2 = false;
        }
    }
    flag2 = true;
    if(find(result.begin(), result.end(), '.') != result.end()){
        for(int i = result.size() - 1; i >= 0; i--){
            if(flag2 && result[i] == '0'){
                flag[i] = false;
            }else if(flag2 && result[i] == '.'){
                flag[i] = false;
                flag2 = false;
            }else if(flag2 && result[i] != '0'){
                flag2 = false;
            }
        }
    }
    for(int i = 0; i < result.size(); i++){
        if(flag[i])
            cout<<result[i];
    }
    return 0;
}