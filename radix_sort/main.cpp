#include <cstdio>
#include <cstring>
#include <algorithm>
#define DN 500005
using namespace std;
int n,v[DN],vnou[DN],cnt[12];

int main()
{
    freopen("algsort.in","r",stdin);
    freopen("algsort.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
    for(int pc=1,pz=1; pc<11; ++pc,pz*=10) {
        for(int j=0; j<=10; ++j) cnt[j]=0;
        for(int i=1; i<=n; ++i) {
            int cc=(v[i]/pz)%10;
            ++cnt[cc+1];
        }
        for(int j=1; j<=11; ++j) cnt[j]+=cnt[j-1];
        for(int i=1; i<=n; ++i) {
            int cc=(v[i]/pz)%10;
            //cerr<<cc<<' ';
            ++cnt[cc];
            vnou[cnt[cc]]=v[i];
        }
        //memcpy(v,vnou,(n+1)*sizeof(int));
        //for(int i=1; i<=n; ++i) v[i]=vnou[i];
        copy(vnou+1,vnou+n+1,v+1);
    }
    for(int i=1; i<=n; ++i) printf("%d ",v[i]);
    return 0;
}
