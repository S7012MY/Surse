#include <fstream>
#define zeros(x) (((x)^((x)-1))&(x))
using namespace std;

int n,m,aib[100005];

void update(int p,int v) {
    for(int i=p; i<=n; i+=zeros(i)) aib[i]+=v;
}

int query(int ld) {
    int r=0;
    for(int i=ld; 0<i; i-=zeros(i)) r+=aib[i];
    return r;
}

int t3(int s) {
    int i,st=1;
    for(;st<n; st<<=1);
    for(i=0;st;st>>=1) if(i+st<=n && s>=aib[i+st]) {
        i+=st;s-=aib[i];
        if(0==s) return i;
    }
    return -1;
}

int main()
{
    ifstream f("aib.in");
    ofstream g("aib.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        int e;
        f>>e;
        update(i,e);
    }
    for(int i=1; i<=m; ++i) {
        int op,a,b;
        f>>op;
        if(0==op) {
            f>>a>>b;
            update(a,b);
        }else if(1==op) {
            f>>a>>b;
            g<<query(b)-query(a-1)<<'\n';
        }else {
            f>>a;
            g<<t3(a)<<'\n';
        }
    }
    return 0;
}
