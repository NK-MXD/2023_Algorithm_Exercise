#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv){
    if(argc != 2){
        cout<<"ERROR: Need a string.";
        return -1;
    }
    string str = argv[1];
    unordered_map<string, int> map;
    // 测试 Segmentation fault
    // int* ptr = nullptr;
    // *ptr = 42; // 尝试写入空指针
    // two
    for (size_t i = 0; i < str.size() - 1; i++) {
        string pair = str.substr(i, 2);
        transform(pair.begin(), pair.end(), pair.begin(), ::tolower); 
        map[pair]++;
    }

    // thress
    for (size_t i = 0; i < str.size() - 2; i++) {
        string pair = str.substr(i, 3);
        transform(pair.begin(), pair.end(), pair.begin(), ::tolower); 
        map[pair]++;
    }

    // 输出所有组合和频数
    for (auto m : map) {
        cout << m.first << " " << m.second << endl;
    }
    return 0;
}
