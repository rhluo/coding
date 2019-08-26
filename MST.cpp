#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,t;
const int N = 1005,M = 40005;
struct Edge{
    int u,v,w;
}e[M];
int pre[N]; //记录前驱.
int id[N],vis[N],in[N];
int dirMst(int root){
    int ans=0;
    while(1){
        memset(in,INF,sizeof(in));
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(w<in[v] && v!=u){
                pre[v]=u;
                in[v]=w;
            }
        }             //求最小入边集
        in[root]=0;
        pre[root]=root;
        for(int i=0;i<n;i++){
            if(in[i]==INF) return -1;
            ans+=in[i];
        }
        int idx = 0; //新标号
        for(int i=0;i<n;i++){
            if(vis[i] == -1 ){
                int u = i;
                while(vis[u] == -1){
                    vis[u] = i;
                    u = pre[u];
                }
                if(vis[u]!=i || u==root) continue;     //判断是否形成环
                for(int v=pre[u];v!=u;v=pre[v] )
                    id[v]=idx;
                id[u] = idx++;
            }
        }
        if(idx==0) break;
        for(int i=0;i<n;i++){
            if(id[i]==-1) id[i]=idx++;
        }
        for(int i=1;i<=m;i++){
            e[i].w-=in[e[i].v];
            e[i].u=id[e[i].u];
            e[i].v=id[e[i].v];
        }
        n = idx;
        root = id[root];//给根新的标号
    }
    return ans;
}

int main(){
    cin>>t;
    int cnt = 0;
    while(t--){
        cnt++;
        scanf("%d%d",&n,&m);

        int count = 1;

        for(int i = 1;i <= n;i++) {
            e[count].u = 0;
            e[count].v = i;
            scanf("%d", &e[count].w);
            count++;
        }

        for(int i=1;i<=m;i++) {
            scanf("%d%d%d",&e[count].u,&e[count].v,&e[count].w);
            count++;
        }

        m = n + m;//修改边的数量为n+m
        n = n + 1;//修改节点数量为n+1,因为把自己作为0加入图中了

        cout << "current n : " << n << "current m :" << m << endl;
        for(int i = 1;i <= m; i++) {
            cout << "edge : " << e[i].u << " " << e[i].v << " " << e[i].w << endl;
        }

        printf("Case #%d: ",cnt);
        int res=dirMst(0);
        if(res==-1) puts("Possums!");
        else cout<<res<<endl;
    }
}
/*
2
5 8
2 8 5 1 10
1 2 5
1 3 9
3 4 5
2 5 6
3 2 2
1 3 8
5 3 4
4 1 8
5 8
7 2 9 10 3
1 2 8
1 3 6
1 4 4
2 5 3
4 5 2
2 4 9
3 5 3
5 4 2

 */