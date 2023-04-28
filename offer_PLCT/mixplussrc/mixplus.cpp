#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<string>
using namespace std;

bool convertToNum(string s, long& num){
        string pattern = "0[xX][0-9a-fA-F]+";
        regex re(pattern);
        if(regex_match(s, regex("[-+]?[0-9]*"))){
                sscanf(s.c_str(), "%ld", &num);
        }
        else if(regex_match(s, re)){
                sscanf(s.c_str(), "%lx", &num);
        }
        else{
                return false;
        }
        return true;
}

int main(int argc, char** argv){
        if(argc != 3){
                cout<<"ERROR"<<endl;
                return -1;
        }
        string s1, s2;
        s1 = argv[1];
        s2 = argv[2];
        long sum = 0;
        long i1, i2;
        bool flag1 = convertToNum(s1, i1);
        bool flag2 = convertToNum(s2, i2);
        if(!flag1 || !flag2){
                cout<<"ERROR"<<endl;
                return -1;
        }
        sum = i1 + i2;
        printf("0x%lx %ld\n", sum, sum);
        return 0;
}
