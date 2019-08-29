//todo kick start B : Energy Stones
//todo greedy & dp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;
int n;
int m;
const int M = 10005;
struct stone{
    int s, e, l;
    bool operator< (const struct stone & st) {
        return s*st.l < st.s*l;
    }
}stones[N];
int dp[N][M];

int solve() {
    memset(dp, 0, sizeof dp);

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] = dp[i-1][j];
            //dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(j >= stones[i].s)
                dp[i][j] = max(dp[i][j], dp[i-1][j - stones[i].s] + max(0, stones[i].e - stones[i].l*(j - stones[i].s)));
        }
    }

//    for(int i = 0;i <= n;i++) {
//        for(int j = 0;j <= m;j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    int rslt = 0;
    for(int i = 1;i <= m;i++) {
        rslt = max(rslt, dp[n][i]);
    }

    return rslt;
}

int main() {
    int T;
    cin >> T;

    for(int cases = 1;cases <= T;cases++) {
        cin >> n;
        m = 0;
        for(int i = 1;i <= n;i++) {
            cin >> stones[i].s >> stones[i].e >> stones[i].l;
            m += stones[i].s;
        }

        sort(stones + 1, stones + n + 1);

//        for(const auto & item : stones) {
//            cout << item.s << " " << item.e << " " << item.l << endl;
//        }

        int rslt = solve();
        printf("Case #%d: %d\n", cases, rslt);
    }

    return 0;
}
/*
1
4
20 10 1
5 30 5
100 30 1
5 80 60

3
4
20 10 1
5 30 5
100 30 1
5 80 60
3
10 4 1000
10 3 1000
10 8 1000
2
12 300 50
5 200 0

Case #1: 105
Case #2: 8
Case #3: 500
 */