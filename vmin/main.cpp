#include <stdio.h>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define LL long long
#define DN 100005
using namespace std;

vector<pair<LL, int> > v;
LL a[DN], b[DN];
int n,i,j,k,m,li,ls,dq[DN];
LL ti,start[DN];


int main() {
    freopen("vmin.in", "r", stdin);
    freopen("vmin.out", "w", stdout);
    scanf("%d %d",&n,&m);
    for (i=1; i<=n;++i) {
        scanf("%lld %lld", &a[i], &b[i]);
        v.push_back(make_pair(b[i],i));
    }
    sort(v.begin(), v.end());
    li=ls=1;
    dq[1]=v[0].y;
    start[1]=0;
    for(i=1;i<n; ++i) {
        j=v[i].y;
        if(a[j]>=a[dq[ls]]) continue;
        for(;ls>=1;--ls) {
            k=dq[ls];
            ti=(b[j]-b[k])/(a[k]-a[j]);
            if(((b[j]-b[k])%(a[k]-a[j]))>0) ++ti;
            if(ti>start[ls]) break;
        }
        dq[++ls]=j;
        if(ls>1) start[ls]=ti;
        else start[ls]=0;
    }
    for(;m;--m) {
        LL t;
        scanf("%lld", &t);
        for(;li<ls && t>=start[li+1];++li);
        printf("%d ", dq[li]);
    }
    return 0;
}
