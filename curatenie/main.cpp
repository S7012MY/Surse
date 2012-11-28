#include <iostream>
#include <fstream>
#define DN 500005
using namespace std;

int n,a[DN],poz[DN],fs[DN],fd[DN];
int ls[DN],ld[DN];//in ce interval are fii
int st[DN],sz;

int main()
{
    ifstream f("curatenie.in");
    ofstream g("curatenie.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        int x;
        f>>x;
        poz[x]=i;
    }
    for(int i=1; i<=n; ++i) f>>a[i];
    st[++sz]=a[1];
    ls[a[1]]=1; ld[a[1]]=n;
    for(int i=2; i<=n; ++i) {
        for(;sz;--sz) {
            int tp=st[sz];
            if(poz[a[i]]>=ls[tp] && poz[a[i]]<=ld[tp]) {
                if(poz[a[i]]<poz[tp]) {
                    fs[tp]=a[i];
                    ls[a[i]]=ls[tp];
                    ld[a[i]]=poz[tp]-1;
                }
                else {
                    fd[tp]=a[i];
                    ls[a[i]]=poz[tp]+1;
                    ld[a[i]]=ld[tp];
                }
                st[++sz]=a[i];
                break;
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        g<<fs[i]<<' '<<fd[i]<<'\n';
    }
    return 0;
}
