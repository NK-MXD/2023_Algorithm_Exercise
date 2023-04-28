#include <iostream>
#include <cmath>
using namespace std;

bool not_double(const char* arg) {
    char* endptr;
    double num = strtod(arg, &endptr);
    if ((num == 0) && (endptr == arg)) {
        return true;
    } else if (std::isnan(num)) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv)
{
    if (argc != 9){
        cout << "FALSE" << endl;
        return 0;
    }
    // 处理参数不为double的情况
    if(not_double(argv[1])||not_double(argv[2])||not_double(argv[3])||not_double(argv[4])||
       not_double(argv[5])||not_double(argv[6])||not_double(argv[7])||not_double(argv[8])){
        cout << "FALSE" << endl;
        return 0;
    }
    double x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = atof(argv[1]);
    y1 = atof(argv[2]);
    x2 = atof(argv[3]);
    y2 = atof(argv[4]);
    x3 = atof(argv[5]);
    y3 = atof(argv[6]);
    x4 = atof(argv[7]);
    y4 = atof(argv[8]);
    // 测试 Segmentation fault
    // int* ptr = nullptr;
    // *ptr = 42; // 尝试写入空指针
    double k1, k2, b1, b2;
    double x, y; //交点的坐标
    // 计算斜率与截距
    if(abs(x1 - x2) < 1e-8 && abs(x3 - x4) < 1e-8){
        cout << "FALSE" << endl;
        return 0;
    }else if(abs(x1 - x2) < 1e-8){
        k2 = (y4 - y3) / (x4 - x3);
        b2 = y3 - k2 * x3; 
        x = x1;
        y = k2 * x + b2;
    }else if(abs(x3 - x4) < 1e-8){
        k1 = (y2 - y1) / (x2 - x1);
        b1 = y1 - k1 * x1; 
        x = x3;
        y = k1 * x + b1;
    }else{
        k1 = (y2 - y1) / (x2 - x1);
        k2 = (y4 - y3) / (x4 - x3);
        if (abs(k1 - k2) < 1e-8) {
            cout << "FALSE" << endl;
            return 0;
        }
        b1 = y1 - k1 * x1; 
        b2 = y3 - k2 * x3; 
        x = (b2 - b1) / (k1 - k2);
        y = k1 * x + b1;
    }
    if (x >= min(x1, x2) && x <= max(x1, x2) && x >= min(x3, x4) && x <= max(x3, x4) &&
        y >= min(y1, y2) && y <= max(y1, y2) && y >= min(y3, y4) && y <= max(y3, y4)){
        cout << "TRUE" << endl;
        return 0;
    }
    else{
        cout << "FALSE" << endl;
        return 0;
    }
    return 0;
}