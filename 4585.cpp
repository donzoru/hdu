#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+4;
struct Tre{
    int id,fp,r,s;
    int a[2];
    Tre(){}
    Tre(int id,int fp,int r):id(id),fp(fp),r(r){
        s=1;
        a[0]=a[1]=0;
    }
    int cmp(int x){
        if(x==fp) return -1;
        return x < fp ? 0 : 1;
    }
}T[M];
int cnt,rt,t;
void init(){
    cnt=1;
    rt=0;
}
void rot(int &r,int f){
    int k=T[r].a[f^1];
    T[r].a[f^1]=T[k].a[f];
    T[r].s -= T[T[k].a[f^1]].s+1;
    T[k].a[f]=r;
    T[k].s += T[T[r].a[f]].s+1;
    r=k;
}
void ins(int &r,int id,int fp)
{
    if(r==0)
        T[r=cnt++]=Tre(id,fp,rand());
    else{
        ++T[r].s;
        int k=T[r].cmp(fp);
        if(k) t+=T[T[r].a[0]].s+1;
        ins(T[r].a[k],id,fp);
        if(T[T[r].a[k]].r > T[r].r)
            rot(r,k^1);
    }
}
int fin(int &r,int k)
{
    if(k==T[T[r].a[0]].s+1)
        return r;
    else if(k > T[T[r].a[0]].s + 1)
        return fin(T[r].a[1],k-T[T[r].a[0]].s-1);
    else
        return fin(T[r].a[0],k);
}
int main()
{
    int n,a,b;
    while(scanf("%d",&n) && n){
        init();
        ins(rt,1,1000000000);
        for(int i=0;i<n;++i){
            scanf("%d%d",&a,&b);
            printf("%d ",a);
            t=1;
            ins(rt,a,b);
            if(t!=1){

                int c=fin(rt,t-1);
                int d=fin(rt,t+1);
                a = T[d].fp - b - b + T[c].fp;
                if(a < 0) printf("%d\n",T[d].id);
                else printf("%d\n",T[c].id);
            }else {
                printf("%d\n",T[fin(rt,t+1)].id);
            }
        }
    }
    return 0;
}
