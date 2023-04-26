#include<iostream>
#include <iomanip>
using namespace std;

//使用二分法求解立方根
int main(){
    double input;
    cin >> input;
    int sign = input > 0? 1: -1;
    input = input *sign;
    double left = 0;
    double right = input > 1? input: 1;
    double mid;
    while(right - left > 1.0e-2){
        mid = (right + left) * 0.5;
        if(mid*mid*mid < input){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout<<fixed<<setprecision(1)<<mid*sign;
}