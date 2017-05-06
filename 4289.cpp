#include<bits/stdc++.h>
using namespace std;
const int M = 510;
const int INF = 0x3f3f3f3f;
int d[M];
int head[M];
int n,m,cnt;
struct edge{
    int f,t,w,n;
    edge() {}
    edge(int f,int t,int w,int n):f(f),t(t),w(w),n(n){}
}edg[M*M];
int st,ed;
bool bfs()
{
    memset(d,-1,sizeof(d));
    d[st]=0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=head[x];i!=-1;i=edg[i].n)
            if(edg[i].w!=0 && d[edg[i].t]==-1)
                d[edg[i].t]=d[x]+1,q.push(edg[i].t);
    }
    return d[ed]!=-1;
}
int dfs(int u,int big)
{
    if(u==ed) return big;
    int dt=big;
    for(int i=head[u];i!=-1;i=edg[i].n){
        if(edg[i].w>0 && d[edg[i].t]==d[u]+1){
            int f=dfs(edg[i].t,min(dt,edg[i].w));
            edg[i].w-=f;
            edg[i^1].w+=f;
            dt-=f;
        }
    }
    return big-dt;
}
int dinic()
{
    int res=0,flow;
    while(bfs())
        res+=dfs(st,INF);
    return res;
}
void add(int f,int t,int w)
{
    edg[cnt]=edge(f,t,w,head[f]);
    head[f]=cnt++;
    edg[cnt]=edge(t,f,0,head[t]);
    head[t]=cnt++;
}
void build()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    int a,b,c;
    scanf("%d%d",&st,&ed);
    ed+=n;
    for(int i=1;i<=n;++i){
        scanf("%d",&c);
        add(i,n+i,c);
    }
    while(m--){
        scanf("%d%d",&a,&b);
        add(n+a,b,INF);
        add(n+b,a,INF);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        build();
        printf("%d\n",dinic());
    }
    return 0;
}
/*
5 6
5 3
5
2
3
4
12
1 5
5 4
2 3
2 4
4 3
2 1
*/
