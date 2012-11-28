#include <cstdio>
#include <set>
#include <vector>
#define DN 100005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

set<int> frunze;
int grad[DN],n,lst[DN];

int main()
{
    freopen("lista.in","r",stdin);
    freopen("lista.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<n; ++i) {
        scanf("%d",&lst[i]);
        ++grad[lst[i]];
    }
    for(int i=1; i<=n; ++i) if(0==grad[i]) frunze.insert(i);
    for(int i=1; i<n; ++i) {
       // deb(1)
        int frz=*frunze.begin();
        printf("%d %d\n",*frunze.begin(),lst[i]);
        frunze.erase(frunze.begin());
        --grad[lst[i]]; ++grad[frz];
        if(0==grad[lst[i]]) frunze.insert(lst[i]);
    }
    return 0;
}
