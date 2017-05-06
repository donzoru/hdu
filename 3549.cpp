#include<bits/stdc++.h>
using namespace std;
const int M = 1002;
const int INF = 0x3f3f3f3f;
int g[M][M];
int d[M];
int n,m;
bool bfs()
{
    memset(d,-1,sizeof(d));
    queue<int> q;
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=1;i<=n;++i)
            if(g[x][i]!=0 && d[i]==-1)
                d[i]=d[x]+1,q.push(i);
    }
    return d[n]!=-1;
}
int dfs(int u,int b)
{
    if(u==n) return b;
    int dt=b;
    for(int i=1;i<=n;++i){
        if(g[u][i]>0 && d[i]==d[u]+1){
            int f=dfs(i,min(dt,g[u][i]));
            g[u][i]-=f;
            g[i][u]+=f;
            dt-=f;
        }
    }
    return b-dt;
}
int dinic()
{
    int res=0,flow;
    while(bfs())
        while(flow=dfs(1,INF))
            res+=flow;
    return res;
}
int main()
{
    int t,cnt=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]+=c;
        }
        printf("Case %d: %d\n",cnt++,dinic());
    }
    return 0;
}
/*
2
3 2
1 2 1
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/
