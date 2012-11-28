#include <fstream>
#include <iostream>
using namespace std;

int n,ns,v[25];
bool fol[25];

ofstream g("nrperm.out");

void bk(int k,int emax, int emin) {
    if(k>n) {
         g<<++ns<<":";
         g<<n<<'\n';
                for(int i=1; i<=n; ++i) g<<v[i]<<' ';
                g<<'\n';
        return;
    }
        bool ok=0;
        int cemin=emin,cemax=emax;
    for(int i=1;i<=n; ++i) if(0==fol[i]) {
                if(k==1) g<<'\n';
                if(i<emin) {
                        cemin=i;
                        ok=1;
                }
                if(i>emax) {
                        cemax=i;
                        ok=1;
                }
                //if(ok) cout<<k<<' '<<i<<' '<<cemin<<' '<<cemax<<'\n';
                if(ok) {
                        fol[i]=1;
                        v[k]=i;
                        bk(k+1,cemax,cemin);
                        fol[i]=0;
                        ok=0;
                        cemax=emax;cemin=emin;
                }
    }
}

int main()
{
        for(n=1; n<=13; ++n) {
                ns=0;
                g<<"N="<<n<<"\n";
                bk(1,0,999);
                cout<<"\nNumar solutii:\n"<<ns;
        }
    return 0;
}
