#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>n;
        printf("Case #%d: %I64d\n",i+1,(n+2)*(n-1)/2);
    }
    return 0;
}
