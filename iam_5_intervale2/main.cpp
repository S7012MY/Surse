#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 100005
using namespace std;

int n,s[DN],p[DN],aib[DN],ind[DN],rez[DN];

bool cmp(const int &a,const int &b) {
    if(s[a]==s[b]) return a>b;
    return s[a]>s[b];
}

int lsb(int n) {
    return (n^(n-1))&n;
}

void ins(int x) {
    for(int i=x; i<=n;i+=lsb(i)) ++aib[i];
}

int query(int x) {
    int ret=0;
    for(int i=x; i>0; i-=lsb(i)) ret+=aib[i];
    return ret;
}

int main()
{
    ifstream f("intervale2.in");
    ofstream g("intervale2.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>s[i];
        ind[i]=i;
    }
    for(int i=1; i<=n; ++i) f>>p[i];
    sort(ind+1,ind+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        int ls=p[ind[i]],ld=ind[i];
        rez[ind[i]]=query(ld)-query(ls-1);
        ins(ind[i]);
    }
    for(int i=1; i<=n; ++i) g<<rez[i]<<' ';
    return 0;
}
