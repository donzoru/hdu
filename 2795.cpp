#include<bits/stdc++.h>
using namespace std;
const int M = 2e5+10;
typedef long long ll;
ll Tree[M<<2];
int h,n;
ll w;
void build(int l,int r,int pos)
{
    if(l==r) {
        Tree[pos]=w;
        return;
    }
    int m=l+r>>1;
    build(l,m,pos<<1);
    build(m+1,r,pos<<1|1);
    Tree[pos]=max(Tree[pos<<1],Tree[pos<<1|1]);
}
int que(int l,int r,int pos,ll L)
{
    if(Tree[pos] < L) return -1;
    if(l==r) {

        Tree[pos]-=L;
        return l;
    }
    int res;
    int m=l+r>>1;
    if(L <= Tree[pos<<1])
        res=que(l,m,pos<<1,L);
    else
        res=que(m+1,r,pos<<1|1,L);
    Tree[pos]=max(Tree[pos<<1],Tree[pos<<1|1]);
    return res;
}
int main()
{
    while(~scanf("%d%I64d%d",&h,&w,&n)){
        h=min(h,n);
        build(1,h,1);
        ll L;
        while(n--){
            scanf("%I64d",&L);
            printf("%d\n",que(1,h,1,L));
        }
    }
    return 0;
}
