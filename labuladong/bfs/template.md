一般bfs的思路是选择一个队列, 每次将一个节点放到队列当中.

例如以下问题: 计算从起点到终点的最近距离
```cpp
int bfs(Node start, Node target){
    queue<Node> q;
    unordered_map<Node> visited;
    q.insert(start);
    visited.insert(start);
    int step = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            Node cur = q.front();
            q.pop();
            if(cur == target){
                return step;
            }
            for(Node x: cur.adj()){
                if(visited.count(x) == 0){
                    q.push(x);
                    visited.insert(x);
                }
            }
        }
        step++;
    }
}
```