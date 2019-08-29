//todo kick start E: Cherries Mesh
//todo MST

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10, M = 2e5+10, INF = 0x3f3f3f3f;

int n, m;
int p[N];//祖宗节点

struct Edge {
    int u, v, w;

    bool operator < (const Edge & T) const {
        return w < T.w;
    }

}edges[M];

int find(int x) {
    //并查集核心
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges+m);
    for(int i = 1; i <= n; i++) p[i] = i; //初始化并查集

    int res = 0, cnt = 0;
    //res 最小生成树中的权重之和
    //cnt 当前加了多少条边

    for(int i = 0; i < m; i++) {
        auto t = edges[i];
        t.u = find(t.u), t.v = find(t.v);
        if(t.u != t.v) {
            p[t.u] = t.v;
            res += t.w;
            cnt++;
        }
    }

    if(cnt < n - 1) return res + (n - 1 - cnt)*2;
    return res;
}

int main(){
    int T;
    cin >> T;
    for(int cases = 1;cases <= T;cases++) {
        cin >> n >> m;
        for(int i = 0;i < m;i++) {
            int u, v;
            cin >> u >> v;
            edges[i] = {u, v, 1};
        }

        int rslt = kruskal();
        printf("Case #%d: %d\n", cases, rslt);
    }

    return 0;
}
/*
2
2 1
1 2
3 1
2 3


 */