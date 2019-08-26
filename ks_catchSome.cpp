//todo kick start: Catch Some
//todo acWing 834 看狗: https://www.acwing.com/problem/content/836/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;
int pos[N], color[N];
vector<int> dogs[N];
int f[N][N], g[N][N];

/**
 * 两个思路：分组背包+前缀和后缀和
 * 分组背包请参考: https://www.acwing.com/problem/content/9/
 * @return
 */
int main() {
    int T;
    cin >> T;
    for(int cases = 1;cases <= T; cases++) {
        int n, m;
        cin >> n >> m;
        for(int i = 0;i < n;i++) cin >> pos[i];
        for(int i = 0;i < n;i++) cin >> color[i];

        for(int i = 1;i <= 1000; i++) dogs[i].clear();
        for(int i = 0;i < n; i++) dogs[color[i]].push_back(pos[i]);
        for(int i = 1; i <= 1000; i++) sort(dogs[i].begin(), dogs[i].end());

        memset(f, 0x3f, sizeof f);
        memset(g, 0x3f, sizeof g);
        f[0][0] = g[1001][0] = 0;

        for(int i = 1;i<= 1000;i++) {
            for(int j = 0;j <= m;j++) {
                f[i][j] = f[i-1][j];
                for(int k = 0;k < dogs[i].size() && k + 1 <= j; k++) {
                    f[i][j] = min(f[i][j], f[i-1][j-k-1] + dogs[i][k]*2);
                }
            }
        }

        for(int i = 1000;i >= 1;i--) {
            for(int j = 0;j <= m;j++) {
                g[i][j] = g[i+1][j];
                for(int k = 0;k < dogs[i].size() && k + 1 <= j; k++) {
                    g[i][j] = min(g[i][j], g[i+1][j-k-1] + dogs[i][k]*2);
                }
            }
        }

        int rslt = 1e9;
        for(int i = 1;i <= 1000; i++) {
            for(int j = 0;j < dogs[i].size() && j+1 <= m;j++) {
                for(int k = 0;k + j + 1<= m;k++) {
                    rslt = min(rslt, f[i-1][k] + g[i+1][m - k - j - 1] + dogs[i][j]);
                }
            }
        }

        printf("Case #%d: %d\n", cases, rslt);
    }

    return 0;
}
/*
3
4 3
1 2 4 9
3 3 2 3
4 3
1 2 3 4
1 8 1 8
6 6
4 3 3 1 3 10000
1 2 8 9 5 7

Case #1: 8
Case #2: 6
Case #3: 10028
 */