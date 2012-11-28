#include <cstdio>
#include <algorithm>
#define DN 100005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
#define x first
#define y second
#define DA 2*131072
using namespace std;

typedef pair<int,int>per;

unsigned short ai[DA];
int n,k,rez,lrez,rrez;

bool cmp(const per &a, const per &b) {
    if(a.x==b.x) return a.y<b.y;
    return a.x>b.x;
}

int update(int p,int vn=1,int ls=1,int ld=n) {
    if(ls==ld) {
        ai[vn]=1;
        return 1;
    }
    int fs,m,pins;
    fs=vn<<1;
    m=(ls+ld)>>1;
    if(p<=m) pins=update(p,fs,ls,m);
    else pins=update(p,fs+1,m+1,ld)+ai[fs];
    ai[vn]=ai[fs]+ai[fs+1];
    return pins;
}

int search(int ce_caut,int sum=0,int vn=1, int ls=1, int ld=n) {
    if(ls==ld) return ld;
    int fs,m;
    fs=vn<<1;
    m=(ls+ld)>>1;
    if(sum+ai[fs]>=ce_caut) return search(ce_caut,sum,fs,ls,m);
    else return search(ce_caut,sum+ai[fs],fs+1,m+1,ld);
}

int main()
{
    per s[DN];
    freopen("ksecv.in","r",stdin);
    freopen("ksecv.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&s[i].x);
        s[i].y=i;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        int p=s[i].y,pins=update(s[i].y),sol;

        if(pins+k+1>i) sol=n;
        else sol=search(pins+k+1)-1;

        if(sol-p+1>rez || (sol-p+1==rez && p<lrez)) {
            rez=sol-p+1;
            lrez=p;rrez=sol;
            int cnt=0;
        }
    }
   // deb((sizeof(ai)+sizeof(s))/(1000*1000));
    printf("%d %d\n",lrez,rrez);
    return 0;
}
