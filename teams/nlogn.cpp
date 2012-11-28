#include <fstream>
#include <algorithm>
#define DN 100005
using namespace std;

int n,a,b,s[DN],rez;

int cb(int el) {
    if(el<0) return 0;
    int ls=1,ld=n,m;
    for(;ls<ld;) {
        m=(ls+ld)>>1;
        if(s[m]<el) ls=m+1;
        else ld=m;
    }
    for(;s[ls]>el;--ls);
    for(;s[ls]<=el && ls<=n;++ls);
    --ls;
    return ls;
}

int main()
{
    ifstream f("teams.in");
    ofstream g("teams.out");
    f>>n>>a>>b;
    for(int i=1; i<=n; ++i) f>>s[i];
    sort(s+1,s+n+1);
    for(int i=1; i<=n; ++i) {
        rez+=cb(b-s[i])-cb(a-s[i]-1);
       // g<<b-s[i]<<' '<<cb(b-s[i])<<'\n';
        //g<<a-s[i]-1<<' '<<cb(a-s[i]-1)<<'\n';
        if(s[i]<=b-s[i]) --rez;
        if(s[i]<=a-s[i]-1) ++rez;
    }
    g<<rez/2;
    return 0;
}
