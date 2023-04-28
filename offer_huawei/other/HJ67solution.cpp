#include <iostream>
#include <vector>
using namespace std;

vector<int> nums(4);
vector<int> res(4);

bool dfs(int sum){
    if(sum == 24) return true;
    for(int i = 0; i < 4;i++){
        if(res[i] == 0){
            res[i] = 1;
            if(dfs(sum + nums[i])) return true;
            if(dfs(sum - nums[i])) return true;
            if(dfs(sum * nums[i])) return true;
            if(sum % nums[i] == 0 && dfs(sum/nums[i])) return true;
            res[i] = 0;
        }
    }
    return false;
}

int main() {
    while (cin >> nums[0]>>nums[1]>>nums[2]>>nums[3]) { // 注意 while 处理多个 case
        // 每两个数字之间有4中选择,不能重复
        if(dfs(0)) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}
// 64 位输出请用 printf("%lld")