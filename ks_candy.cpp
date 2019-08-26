//todo kick start: Candy
//todo acWing 546 糖果: https://www.acwing.com/problem/content/548/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;

LL x[500010], s[500010];

int main() {
    int T;
    cin >> T;
    for(int cases = 1;cases <= T; cases++) {
        int n, o;
        LL d;
        int A, B, C, M, L;

        cin >> n >> o >> d;
        cin >> x[1] >> x[2] >> A >> B >> C >> M >> L;
        for(int i = 3;i <= n;i++) x[i] = (A*x[i-1] + B*x[i-2] + C) % M;
        for(int i = 1;i <= n;i++) s[i] = x[i] + L;

        // for(int i = 1;i <= n;i++) cout << s[i] << " ";
        // cout << endl;
        for(int i = 1;i <= n;i++) s[i] += s[i-1];

        LL res = -1e18;

        multiset<LL> S;
        S.insert(0);
        for(int i = 1, j = 0, odds = 0;i <= n; i++) {
            if(s[i] - s[i-1] & 1) odds++;
            while(odds > o) {
                S.erase(S.find(s[j]));
                if(s[j+1] - s[j] & 1) odds--;
                j++;
            }
            //si - sk <= d && max(si - sk) 即需要寻找满足条件最小的sk，使用lower_bound
            auto it = S.lower_bound(s[i] - d);
            if(it != S.end()) res = max(res, s[i] - *it);

            //如果糖果和为负，s[i] - s[i] <= D && max(si - sk)当k==i时最大，
            //这样就可以一个糖果都不吃了，不符合题意最少要吃一个糖果
            S.insert(s[i]);
        }

        if(res == -1e18) printf("Case #%d: IMPOSSIBLE\n", cases);
        else printf("Case #%d: %lld\n", cases, res);
    }

    return 0;
}
/*
5
6 1 1000000000000000
1 1 1 1 0 100 0
6 1 -100
1 1 1 1 0 100 0
10 1 8
4 3 4 1 5 20 -10
10 2 8
4 3 4 1 5 20 -10
10 1 8
4 3 4 1 5 20 -19

Case #1: 13
Case #2: IMPOSSIBLE
Case #3: 7
Case #4: 8
Case #5: -5
 */
