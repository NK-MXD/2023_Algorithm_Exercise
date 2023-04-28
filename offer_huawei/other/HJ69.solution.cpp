#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x, y, z;
    while (cin >> x >> y >> z){
        vector<vector<int>> arr1(x, vector<int>(y, 0));
        vector<vector<int>> arr2(y, vector<int>(z, 0));
        vector<vector<int>> arr3(x, vector<int>(z, 0));
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < y; ++j)
                cin >> arr1[i][j];
        }
        for(int i = 0; i < y; ++i){
            for(int j = 0; j < z; ++j)
                cin >> arr2[i][j];
        }
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < y; ++j)
                for(int k = 0; k < z; ++k)
                    arr3[i][k] += arr1[i][j] * arr2[j][k];
        }
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < z-1; ++j)
                cout << arr3[i][j] << " ";
            cout << arr3[i][z-1] << endl;
        }
    }
    return 0;
}