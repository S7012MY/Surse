#include <iostream>
#include <fstream>
#define DN 200005
#define LL long long
using namespace std;

int n,k,a[DN],b[DN];
LL rez;

bool check(LL cst) {
    LL cnt=0;
    for(int i=1; i<=n; ++i) {
        if(cst<a[i]) continue;
        LL x=(cst-a[i])/b[i]+1;
        cnt+=x;
    }
    return cnt>=k;
}

int main()
{
    ifstream f("tarabe.in");
    ofstream g("tarabe.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) f>>b[i]>>a[i];
    LL ls=1,ld=1,m;
    for(;!check(ld);ld<<=1);
    for(;ls<=ld;) {
        m=(ls+ld)/2LL;
        if(check(m)) {
            rez=m;
            ld=m-1;
        }else ls=m+1;
    }
    LL cnt=0,s=0;
    for(int i=1; i<=n; ++i) {
        if(rez<a[i]) continue;
        LL x=(rez-a[i])/b[i]+1;
        cnt+=x;
        s+=x*a[i]+(x*(x-1))/2*b[i];
    }
    g<<s-rez*(cnt-k);
    return 0;
}
