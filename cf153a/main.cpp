#include <iostream>
#define DN 100005
#define z9 1000000000
using namespace std;

int n,v[DN],d;
long long rez;

int main()
{
    cin>>n>>d;
    for(int i=1,j=1; i<=n; ++i) {
        cin>>v[i];
        v[i]+=z9;
        for(;v[i]-v[j]>d;++j);
        if(i-j>1) {
            long long ct=i-j;
            rez+=(ct*(ct-1LL))/2;
        }
    }
    cout<<rez;
    return 0;
}
