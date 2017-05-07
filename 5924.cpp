#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long a,b;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>a>>b;
        printf("Case #%d:\n",i+1);
        if(a==b)
            printf("1\n%I64d %I64d\n",a,b);
        else
            printf("2\n%I64d %I64d\n%I64d %I64d\n",a,b,b,a);
    }
    return 0;
}
