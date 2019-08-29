//todo kick start B : Diverse Subarray
//todo segment tree
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;
int types[N], a[N];
vector<int> all[N];

struct Node {
    int l, r;
    int s, ps;
}tr[N << 2];

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if(l == r) {
        tr[u].s = tr[u].ps = a[l];
        return;
    }

    int mid = l + r >> 1, left = u << 1, right = left | 1;
    build(left, l, mid), build(right, mid + 1, r);
    tr[u].s = tr[left].s + tr[right].s;
    tr[u].ps = max(tr[left].ps, tr[left].s + tr[right].ps);
}

void update(int u, int k, int v) {
    if(tr[u].l == tr[u].r) {
        a[k] = v;
        tr[u].s = tr[u].ps = v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1, left = u << 1, right = left | 1;
    if(k <= mid) update(left, k, v);
    else update(right, k, v);
    tr[u].s = tr[left].s + tr[right].s;
    tr[u].ps = max(tr[left].ps, tr[left].s + tr[right].ps);
}

int main() {
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++) {
        cin >> n >> m;

        for(int i = 0;i < N; i++) all[i].clear();

        for(int i = 0;i < n;i++) {
            cin >> types[i];
            all[types[i]].push_back(i);
        }

        memset(a, 0, sizeof a);
        for(int i = 0;i < N;i++) {
            for(int j = 0;j < m && j < all[i].size(); j++) a[all[i][j]] = 1;
            if(all[i].size() >= m + 1) a[all[i][m]] = -m;
        }

        build(1, 0, n-1);

        int res = tr[1].ps;
        for(int i = 0;i < n;i++) {
            update(1, i, 0);
            auto indexs = all[types[i]];
            int j = lower_bound(indexs.begin(), indexs.end(), i) - indexs.begin();
            if(j + m < indexs.size()) update(1, indexs[j+m], 1);
            if(j + m + 1 < indexs.size()) update(1, indexs[j+m+1], -m);

            res = max(res, tr[1].ps);
        }

        printf("Case #%d: %d\n", cases, res);
    }

}
/*
4
6 2
1 1 4 1 4 4
8 1
1 2 500 3 4 500 6 7
10 1
100 200 8 8 8 8 8 300 400 100
12 2
40 50 1 1 1 60 70 2 2 2 80 90


Case #1: 4
Case #2: 6
Case #3: 4
Case #4: 6
 */