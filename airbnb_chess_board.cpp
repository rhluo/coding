#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int bfs(int a, int b, int n){
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int,int>> que;
    que.emplace(0, 0);
    int ans = 0;
    while(!que.empty()){
        const int sz = que.size();
        for(int i = 0; i < sz; i++){
            auto top = que.front();que.pop();
            if(top.first < 0 || top.first >= n || top.second < 0 || top.second >= n || visited[top.first][top.second])
                continue;
            if(top.first == n - 1 && top.second == n-1)
                return ans;
            visited[top.first][top.second] = true;
            que.emplace(top.first + a, top.second + b);
            que.emplace(top.first + a, top.second - b);
            que.emplace(top.first - a, top.second + b);
            que.emplace(top.first - a, top.second - b);
            que.emplace(top.first + b, top.second + a);
            que.emplace(top.first + b, top.second - a);
            que.emplace(top.first - b, top.second + a);
            que.emplace(top.first - b, top.second - a);
        }
        ++ans;
    }
    return -1;
}

void dfs(int a, int b, int n, vector<vector<int>> & visited, int x=0, int y=0, int depth=0){
    if(x < 0 || y < 0 || x >= n || y >= n || depth >= visited[x][y])
        return;
    visited[x][y] = depth++;
    dfs(a, b, n, visited, x + a, y - b, depth);
    dfs(a, b, n, visited, x + a, y + b, depth);
    dfs(a, b, n, visited, x - a, y - b, depth);
    dfs(a, b, n, visited, x - a, y + b, depth);
    dfs(a, b, n, visited, x + b, y - a, depth);
    dfs(a, b, n, visited, x + b, y + a, depth);
    dfs(a, b, n, visited, x - b, y - a, depth);
    dfs(a, b, n, visited, x - b, y + a, depth);
}

int main(){
    int a, b, n;
    cin>>a>>b>>n;
    vector<vector<int>> visited(n, vector<int>(n, INT_MAX));
    dfs(a, b, n, visited);
    cout<<visited[n-1][n-1]<<endl;
    cout<<bfs(a, b, n)<<endl;
    return 0;
}