#include <cstdio>
#include <algorithm>
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
#define DN 10005
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
    freopen("inversiuni.in","r",stdin);
    freopen("inversiuni.out","w",stdout);
    for(;scanf("%d",&n)==1;){
        rez=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d",&s[i]);
            aib[i]=0;
            ind[i]=i;
        }
        sort(ind+1,ind+n+1,cmp);
        for(int i=1; i<=n; ++i) {
            rez+=query(ind[i]);
            ins(ind[i]);
        }
        printf("%d\n",rez);
    }
    return 0;
}
