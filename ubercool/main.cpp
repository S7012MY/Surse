#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#define LL long long
#define z9 1000000000
#define z18 1000000000000000000LL
using namespace std;

int t;
bitset<10000005> isp;
vector<LL> pr;
LL x[5555];
map<LL,string> s;

void c() {
    for(LL i=2; i*1LL*i<=2000000; ++i) if(!isp[i]) {
        for(LL j=i*i; j<=2000000; j+=i) isp[j]=1;
    }
    for(int i=2; i<=2000000; ++i) if(!isp[i]) pr.push_back(i);
}

int ip(LL nr) {
    if(nr==0 || nr==1) return 0;
    for(LL i=2; i*i<=nr && i*i<=z9; ++i) if(nr%i==0) return 0;
    return 1;
}

bool cauta(LL nr) {
    if(nr<4) return 0;
    LL ls=1,ld=z9*100,m;
    for(;ls<ld;) {
        m=(ls+ld+1LL)>>1LL;
        if(m*m<=nr) ls=m;
        else ld=m-1;
    }
    for(;ls*ls<=nr; ++ls);
    for(;ls*ls>nr;--ls);
    if(ls*ls==nr && ip(ls)) return 1;
    return 0;
}

int main()
{
    ifstream f("ubercool.in");
    ofstream g("ubercool.out");
    c();
    f>>t;
    LL mx=0;
    for(int i=1; i<=t; ++i) {
        f>>x[i];
        mx=max(mx,x[i]);
        s[x[i]]="NU";
        if(cauta(x[i])) s[x[i]]="DA";
    }
    for(int i=0; i<pr.size(); ++i) {
        LL rp=pr[i]*pr[i];
        for(;rp<=z18; rp*=pr[i]) {
            if(s.find(rp)!=s.end()) s[rp]="DA";
            if(mx/rp<pr[i]) break;
        }
    }
    for(int i=1; i<=t; ++i) {
        g<<s[x[i]]<<'\n';
    }
    return 0;
}
