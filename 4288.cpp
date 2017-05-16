#include<bits/stdc++.h>
using namespace std;
typedef __int64 ll;
const int M = 1e5+10;
#define lsh(x) (x<<1)
#define rsh(x) (x<<1|1)
struct Tree{
    int l,r,cnt;
    ll sum[5];
    int mid(){
        return l+r>>1;
    }
}T[M<<2];
int n;
char cmd[M];
int x[M],num[M];
bool flag;
void build(int l,int r,int pos)
{
    T[pos].l=l; T[pos].r=r; T[pos].cnt=0;
    memset(T[pos].sum,0,sizeof(T[pos].sum));
    if(l==r) return;
    int m=T[pos].mid();
    build(l,m,lsh(pos));
    build(m+1,r,rsh(pos));
}
void update(int k,int pos)
{
    flag ? ++T[pos].cnt : --T[pos].cnt;
    if(T[pos].l==T[pos].r){
        T[pos].sum[1]=flag*x[k-1];// the k-th number
        return;
    }
    int m=T[pos].mid();
    if(k>m)
        update(k,rsh(pos));
    else
        update(k,lsh(pos));
    for(int i=0;i<5;++i){
        int j=(i+T[lsh(pos)].cnt) % 5;
        T[pos].sum[j] = T[lsh(pos)].sum[j]+T[rsh(pos)].sum[i];
    }
}
int main()
{
    char s[5];
    while(~scanf("%d",&n)){
        int cnt=0;
        for(int i=0;i<n;++i){
            scanf("%s",s);
            cmd[i]=s[0];
            if(cmd[i]!='s')
                scanf("%d",&num[cnt++]);
        }
        memcpy(x,num,sizeof(int)*cnt);
        sort(x,x+cnt);
        cnt = unique(x,x+cnt)-x;
        build(1,cnt,1);
        for(int i=0,j=0;i<n;++i){
            if(cmd[i]=='s'){
                printf("%I64d\n",T[1].sum[3]);
                continue;
            }
            int k=lower_bound(x,x+cnt,num[j++])-x+1;
            flag = cmd[i] == 'a' ? 1 : 0;
            update(k,1);
        }
    }
    return 0;
}
/*
9
add 1
add 2
add 3
add 4
add 5
sum
add 6
del 3
sum
6
add 1
add 3
add 5
add 7
add 9
sum
*/
