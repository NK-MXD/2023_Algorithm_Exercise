
// 有0-n-1的n个资源, 每次有两种操作: 分配资源和释放资源;
// 分配资源分为两种, 一种为自动分配资源, 表示方式为A k, 其中k表示自动分配的资源个数; 
// 另一种为手动分配资源, 表示方法为B k, 其中k表示手动分配的资源id; 
// 释放资源表示方法为C k, k表示释放资源的id, 
// 要求: 1. 默认自动分配资源是从资源列表中最前面的资源开始分配的, 
// 2. 如果分配资源的个数大于空闲资源个数则不进行分配
// 3. 默认释放资源之后, 释放的资源放置在空闲资源列表的最后;
// 4. 初始状态时, 资源0-n-1按照从小到大的顺序排列
// 请问m次操作之后, 空闲资源的首资源id

#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <list>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<bool> inFreeResources(n, true);
    std::list<int> freeResources;
    for (int i = 0; i < n; ++i) {
        freeResources.push_back(i);
    }
    std::vector<std::list<int>::iterator> freeResourcesIterators(n);
    {
        int i = 0;
        for (auto it = freeResources.begin(); it != freeResources.end(); ++it, ++i) {
            freeResourcesIterators[*it] = it;
        }
    }

    for (int i = 0; i < m; ++i) {
        char operation;
        int k;
        std::cin >> operation >> k;
        if (operation == 'A') {
            if (k <= (int)freeResources.size()) {
                while (k--) {
                    std::cout << "自动分配资源: " << freeResources.front() << std::endl;
                    inFreeResources[freeResources.front()] = false;
                    // freeResources.erase(freeResourcesIterators[freeResources.front()]);
                    freeResources.pop_front();
                }
            } else {
                std::cout << "自动分配失败：无足够空闲资源" << std::endl;
            }
        } else if (operation == 'B') {
            if (inFreeResources[k]) {
                std::cout << "手动分配资源: " << k << std::endl;
                inFreeResources[k] = false;
                freeResources.erase(freeResourcesIterators[k]);
            } else {
                std::cout << "手动分配失败：资源 " << k << " 不可用" << std::endl;
            }
        } else if (operation == 'C') {
            std::cout << "释放资源：" << k << std::endl;
            inFreeResources[k] = true;
            freeResources.push_back(k);
            freeResourcesIterators[k] = --freeResources.end();
        }
    }

    std::cout << "空闲资源列表首资源ID: " << freeResources.front() << std::endl;

    return 0;
}
