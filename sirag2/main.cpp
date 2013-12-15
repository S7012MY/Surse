#include <iostream>
#include <fstream>
#define DN 100005
using namespace std;

//in deque tin minimul t[i-l+1,...,l]
int T,n,l,a[DN],t[DN],dq[DN],ls,ld,sol;
char v[DN];

int main()
{
    ifstream f("sirag2.in");
    ofstream g("sirag2.out");
    for(f>>T;T--;) {
        ls=sol=1;
        f>>n>>l;
        for(int i=1; i<=n; ++i) f>>v[i];
        for(int i=1; i<=n; ++i) {
            if(i>l && '*'==v[i]) a[i]=a[i-l];
            else a[i]=i;
            t[i]=1;
            if(i>l && ('*'==v[i] || '*'==v[a[i-l]] || v[i]==v[a[i-l]])) t[i]=t[i-l]+1;
            else if(i>l) t[i]=(i-a[i-l])/l;

            for(;ls<=ld &&t[dq[ld]]>=t[i];--ld);
            dq[++ld]=i;
            for(;ls<=ld &&i-dq[ls]>l-1;++ls);
            sol=max(sol,t[dq[ls]]);
        }
        g<<sol*l<<'\n';
    }
    return 0;
}
