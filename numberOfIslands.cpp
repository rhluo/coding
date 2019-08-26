//todo leetcode 200 : dfs, union find

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> dic = {{1,0}, {0,1}, {-1,0}, {0,-1}};

vector<int> f;

int find(int x) {
    if(f[x] != x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

void uni(int x, int y) {
    auto rootx = find(x);
    auto rooty = find(y);
    if(rootx != rooty) {
        f[rootx] = rooty;
    }
}

void printF() {
    for(const auto & it : f) {
        cout << it << " ";
    }
    cout << endl;
}

int numIslandsByUF(vector<vector<char>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    f.resize(n * m, 0);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
//            if(grid[i][j] == '1') {
                f[i * n + j] = i * n + j;
                cout << i << " " << j << endl;
//            }
        }
    }

    printF();

    for(int i = 0;i < n; i++) {
        for(int j = 0;j < m;j++) {
            if(grid[i][j] == '1') {
                for(int k = 0;k < 4;k++) {
                    int nx = i + dic[k][0];
                    int ny = j + dic[k][1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(grid[nx][ny] != '1') continue;
                    uni(n*i+j, nx*n+ny);
                }
            }
        }
    }

    printF();


    unordered_set<int> count;
    for(int i = 0;i < n; i++) {
        for(int j = 0;j < m;j++) {
            if(grid[i][j] == '1') {
                auto root = find(i*n + j);
                if(count.count(root) == 0) {
                    count.insert(root);
                }
            }
        }
    }

    printF();


    return count.size();
}

void dfs(vector<vector<char>>& grid, int x, int y) {
    grid[x][y] = '2';
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0;i < 4; i++) {
        int nx = x + dic[i][0];
        int ny = y + dic[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(grid[nx][ny] == '1') {
            dfs(grid, nx, ny);
        }
    }
}

int numIslands(vector<vector<char>> grid) {
    int n = grid.size();
    int m = grid[0].size();

    int rslt = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(grid[i][j] == '1') {
//                cout << i << " " << j << endl;
                dfs(grid, i, j);
                rslt++;
            }
        }
    }

    return rslt;
}

int main() {
    vector<vector<char>> grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}};

    cout << numIslandsByUF(grid) << endl;

    cout << numIslands(grid) << endl;
//    for(const auto & g : grid) {
//        for(const auto & i : g) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }

    return 1;
}