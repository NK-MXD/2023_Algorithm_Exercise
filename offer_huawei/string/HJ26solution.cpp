#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isParam(char a){
    if(a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
        return true;
    return false;
}

vector<char> temp;

void merge(vector<char>& num, int lo, int mid, int hi){
    for(int i = lo; i <= hi; i++){
        temp[i] = num[i];       
    }

    int i = lo, j = mid + 1;
    for(int p = lo; p <= hi; p++){
        if(!isParam(temp[p])){
            num[p] = temp[p];//这样的话下面的i和j没有增加
            continue;
        }
        while(!isParam(temp[i]) && i < mid + 1) i++;
        while(!isParam(temp[j]) && j < hi + 1) j++;
        char a = temp[i];
        char b = temp[j];
        int A = a >= 'a'? a - 'a': a - 'A';
        int B = b >= 'a'? b - 'a': b - 'A';

        if(i == mid + 1){
            num[p] = temp[j++];
        }else if(j == hi + 1){
            num[p] = temp[i++];
        }else if(B < A){
            num[p] = temp[j++];
        }else{
            num[p] = temp[i++];
        }
    }
}

void sort(vector<char>& num, int lo, int hi){
    if(lo == hi)
        return;
    int mid = lo + (hi - lo)/2;
    sort(num, lo, mid);
    sort(num, mid + 1, hi);
    merge(num, lo, mid, hi);
}


void sort(vector<char>& num){
    temp.resize(num.size());
    sort(num, 0, num.size() - 1);
}


int main() {
    string input;
    vector<char> vc;
    while(getline(cin, input)){
        for(int i = 0; i < input.length(); i++){
            vc.push_back(input[i]);
        }
        //1. 英文字母进行排序, 其它字符的顺序不变, 排序算法, 暂时用普通的
        //这样子的实现不能保证顺序, 需要保证排序的顺序: 这里使用一下归并排序
        sort(vc);
    }
    for(int i = 0; i <vc.size(); i++){
        cout<<vc[i];
    }
    return 0;
}
