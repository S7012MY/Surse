#include <cstdio>
#include <algorithm>
using namespace std;
struct piesa{
        int x;
        int y;
};
piesa p[500005];

bool cmp (const piesa &a,const piesa &b){

        if (a.x==b.x){ return a.y>b.y;}

return a.x<b.x;
}
int t;
int main () {
        freopen("date.in","r",stdin);
        freopen("date.out","w",stdout);
        for(scanf("%d",&t);t;--t) {
            int n,i,c;
            c=1;
            scanf("%d",&n);
            for(i=1;i<=n;++i){
                    scanf("%d %d",&p[i].x,&p[i].y);
            }
            sort (p+1,p+n+1,cmp);
            for(i=1;i<n;++i){
                    if (p[i].y<=p[i+1].x) ++c;
            }
            printf("%d\n",c);
        }
        return 0;
}
