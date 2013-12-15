#include <iostream>
using namespace std;

long long n,p[55],fr[5005],tax[5005];
long long bani;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i];
    for(int i='a'; i<'f'; ++i) cin>>tax[i];
    for(int i=1; i<=n; ++i) {
        bani+=p[i];
        for(int i=1; i<=100; ++i)
        for(int i='e'; i>='a'; --i) if(bani>=tax[i]) {
            long long nr=bani/tax[i];
            bani-=nr*1LL*tax[i];
            fr[i]+=nr;
        }
    }
    for(int i='a'; i<'f'; ++i) cout<<fr[i]<<' ';
    cout<<'\n'<<bani;
    return 0;
}
