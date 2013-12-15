#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <cctype>
#define DN 50005
using namespace std;

string p[DN],s;
int n,m,rez[DN],a[DN],b[DN],ind[DN],cons=128*128;
bitset<DN> ok;

bool cmp(const int &x, const int &y) {
    if(a[x]==a[y]) return b[x]<b[y];
    return a[x]<a[y];
}

inline int conv(char c) {
    if(isdigit(c)) return c-'0';
    if(isupper(c)) return 10+c-'A';
    return 36+c-'a';
}

int main()
{
    ifstream f("pentagrame.in");
    ofstream g("pentagrame.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        ind[i]=i;
        f>>p[i];
        a[i]=conv(p[i][0])*cons+conv(p[i][1])*128+conv(p[i][2]);
        b[i]=conv(p[i][3])*128+conv(p[i][4]);
    }
    sort(ind+1,ind+n+1,cmp);
    for(int i=1; i<=m; ++i) {
        f>>s;
        for(int j=0; j<=s.size()-5; ++j) {
            a[n+1]=conv(s[j])*cons+conv(s[j+1])*128+conv(s[j+2]);
            b[n+1]=conv(s[j+3])*128+conv(s[j+4]);
            int poz=lower_bound(ind+1,ind+n+1,n+1,cmp)-ind;
            if(poz>=0 && poz<=n && a[n+1]==a[ind[poz]]&& b[n+1]==b[ind[poz]] && !ok[poz]) {
                ++rez[poz];
                ok[poz]=1;
            }
        }
        ok&=0;
    }
    int m=0,cnt=0;
    for(int i=1; i<=n; ++i) m=max(m,rez[i]);
    for(int i=1; i<=n; ++i) if(m==rez[i]) ++cnt;
    g<<cnt<<'\n';
    for(int i=1; i<=n; ++i) if(m==rez[i]) g<<p[ind[i]]<<'\n';
    return 0;
}
