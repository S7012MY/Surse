#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include <bitset>
#define DN 50005
using namespace std;

string p[DN],s;
int n,m,rez[DN];
bitset<DN> ok;

bool cmp(const string &a, const string &b) {
    return strcmp(a.c_str(),b.c_str())<0;
}

int main()
{
    ifstream f("pentagrame.in");
    ofstream g("pentagrame.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>p[i];
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1; i<=m; ++i) {
        f>>s;
        for(int j=0; j<=s.size()-5; ++j) {
            string q;
            q.append(s,j,5);
            for(int k=0; k<5; ++k) q+=s[j+k];
            int poz=lower_bound(p+1,p+n+1,q,cmp)-p;
            if(poz>=0 && poz<=n && q.compare(p[poz])==0 && !ok[poz]) {
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
    for(int i=1; i<=n; ++i) if(m==rez[i]) g<<p[i]<<'\n';
    return 0;
}
