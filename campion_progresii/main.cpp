#include <cstdio>
#include <cstring>
#include <vector>
#define DN 50005
#define MOD 2011
#define deb(n) fprintf(stderr,"%d ", (n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef vector<int>::iterator it;
int n,x,lgm[DN],nr[DN]={1},viz[DN]={1};

vector<int> gr[DN];

void dfs(int s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        if(0==viz[*i]) dfs(*i);
        nr[s]+=nr[*i];
        if(nr[s]>=MOD) nr[s]-=MOD;
        if(nr[*i]) lgm[s]=max(lgm[s],lgm[*i]+1);
    }
}

int main()
{
    freopen("progresii.in","r",stdin);
    freopen("progresii.out","w",stdout);
    scanf("%d %d",&n,&x);
    nr[0]=1;
    for(int i=1; i<=n; ++i) {
        int ft,r;
        scanf("%d %d",&ft,&r);
        for(int j=ft+r; j<=x; j+=r) gr[j].push_back(j-r);
    }
    dfs(x);
    printf("%d %d",nr[x],lgm[x]+1);
   // deb(lgm[8])
    return 0;
}
