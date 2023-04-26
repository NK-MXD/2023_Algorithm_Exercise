#include<iostream>
using namespace std;

// 输入起始高度
// 输出第五次落地路径长度与第五次反弹高度
int main() {
    int a;
    double x;
    double height;   
    while (cin >> a) { // 注意 while 处理多个 case
        x = a;
        height = a;
        for(int i = 0; i < 4; i++){
            height = height / 2.0;
            x += 2 * height;
        }
        cout<<x<<std::endl<<height/2.0;
    }
    return 0;
}