#include<bits/stdc++.h>
using namespace std;
const int M = 1002<<1;
int low[M],dfn[M],col[M];
bool vis[M];
stack<int> ss;
int t,n,num;
vector<int> G[M];
void init()
{
    t=num=0;
    for(int i=0;i<n*2;++i){
        vis[i]=false;
        dfn[i]=-1;
        G[i].clear();
    }
    while(!ss.empty()) ss.pop();
}
void tarjan(int k)
{
    dfn[k]=low[k]=t++;
    vis[k]=true;
    ss.push(k);
    for(int i=0;i<G[k].size();++i){
        int v=G[k][i];
        if(dfn[v]==-1){
            tarjan(v);
            low[k]=min(low[k],low[v]);
        }else if(vis[v]) low[k]=min(low[k],dfn[v]);
    }
    if(dfn[k]==low[k]){
        for(int v;;){
            v=ss.top();
            ss.pop();
            vis[v]=false;
            col[v]=num;
            if(v==k) break;
        }
        ++num;
    }
}
int main()
{
    int m,a,b,c,d;
    while(scanf("%d",&n)!=EOF){
        init();
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            G[a*2+c].push_back(b*2+1-d);
            G[b*2+d].push_back(a*2+1-c);
        }
        a=n*2;
        for(int i=0;i<a;++i) if(dfn[i]==-1) tarjan(i);
        a=0;
        for(int i=0;i<n;++i){
            if(col[i<<1]==col[i<<1|1]){
                a=1;
                break;
            }
        }
        if(a==1) puts("NO");
        else puts("YES");
    }
    return 0;
}
