#include<bits/stdc++.h>
using namespace std;
const int M = 1002<<1;
int dfn[M],low[M],col[M];
bool vis[M];
stack<int> ss;
vector<int> g[M];
int cnt,t,num;
void init()
{
    for(int i=0;i<2*t;++i){
        g[i].clear();
        dfn[i]=-1;
        vis[i]=false;
    }
    cnt=num=0;
    while(!ss.empty()) ss.pop();
}
void tarjan(int k)
{
    dfn[k]=low[k]=cnt++;
    ss.push(k);
    vis[k]=true;
    for(int i=0;i<g[k].size();++i){
        int v=g[k][i];
        if(dfn[v]==-1){
            tarjan(v);
            low[k]=min(low[k],low[v]);
        }else if(vis[v]) low[k]=min(low[k],dfn[v]);
    }
    if(dfn[k]==low[k]){
        for(int v=ss.top();;v=ss.top()){
            vis[v]=false;
            col[v]=num;
            ss.pop();
            if(v==k) break;
        }
        ++num;
    }
}
int mem[M<<1];
int main()
{
    int m;
    while(scanf("%d%d",&t,&m)!=EOF){
        init();
        int a,b,c;
        for(int i=0;i<t;++i){
            scanf("%d%d%d",&a,&b,&c);
            mem[a]=i<<1;
            mem[b]=mem[c]=i<<1|1;
        }
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            g[mem[a]].push_back(mem[b]^1);
            g[mem[b]].push_back(mem[a]^1);
        }
        a=t<<1;
        for(int i=0;i<a;++i)
            if(dfn[i]==-1)
                tarjan(i);
        a=0;
        for(int i=0;i<t;++i){
            if(col[i<<1]==col[i<<1|1]){
                a=1;
                break;
            }
        }
        if(a==1) puts("no");
        else puts("yes");
    }
    return 0;
}
