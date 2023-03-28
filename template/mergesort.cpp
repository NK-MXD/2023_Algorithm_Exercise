#include<vector>
using namespace std;

vector<int> temp;

void sort(vector<int>& num){
    temp.resize(num.size());
    sort(num, 0, num.size() - 1);
}

void sort(vector<int>& num, int lo, int hi){
    if(lo == hi)
        return;
    int mid = lo + (hi - lo)/2;
    sort(num, lo, mid);
    sort(num, mid + 1, hi);
    merge(num, lo, mid, hi);
}

void merge(vector<int>& num, int lo, int mid, int hi){
    for(int i = lo; i <= hi; i++){
        temp[i] = num[i];       
    }

    int i = lo, j = mid + 1;
    for(int p = lo; p <= hi; p++){
        if(i == mid + 1){
            num[p] = temp[j++];
        }else if(j == hi + 1){
            num[p] = temp[i++];
        }else if(temp[i] > temp[j]){
            num[p] = temp[j++];
        }else{
            num[p] = temp[i++];
        }
    }
}