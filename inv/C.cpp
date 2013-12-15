#include <fstream>
#include <algorithm>
#define DN 100005
#define MOD 9917
using namespace std;

int n,s[DN],aib[DN],ind[DN],rez;

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
    ifstream f("inv.in");
    ofstream g("inv.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>s[i];
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        rez+=query(ind[i]);
        rez%=MOD;
        ins(ind[i]);
    }
    g<<rez<<'\n';
    return 0;
}
