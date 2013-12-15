#include <cstdio>
#include <vector>
#define DN 250005
#define LL long long
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef vector<int>::iterator is;

int t,n,s[DN],f[DN],bk[DN];
LL rez[DN];
vector<int> cur,prec;

int main()
{
    freopen("zlego.in","r",stdin);
    freopen("zlego.out","w",stdout);
    for(scanf("%d",&t);t;--t) {
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) rez[i]=0;
        for(int i=1; i<=n; ++i) scanf("%d",&s[i]);
        for(int i=1; i<=n; ++i) scanf("%d",&f[i]);

        prec.clear();
        for(int i=1; i<=n; ++i)
            if(s[i]==s[1]) {
                prec.push_back(i);
                rez[1]+=f[i];
            }
        for(int i=2; i<=n; ++i) {
            for(is j=prec.begin(); j!=prec.end(); ++j) {
                int fr=*j;
                if(fr<n && s[fr+1]==s[i]) {
                    rez[i]+=f[fr+1];
                    cur.push_back(fr+1);
                }
            }
            prec=cur;
            cur.clear();
        }

        for(int i=1; i<=n; ++i) {
            //rez[i]+=f[i];
            printf("%lld\n",rez[i]);
        }
    }
    return 0;
}
