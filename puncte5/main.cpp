#include <cstdio>
#include <vector>
#define DC 30193
#define DN 32005
using namespace std;

int n,k,val[DC],mx[DC],gls,gld,vl,mxx;

vector<int> x[5005];

inline void update(int vn, int ls,int ld) {
    if(ls>gld || ld<gls) return;
    if(gls<=ls && ld<=gld) {
        val[vn]+=vl;
        mx[vn]+=vl;
        return;
    }
    int fs=(vn<<1),m=(ls+ld)>>1;
    if(gls<=m) update(fs,ls,m);
    if(m<gld) update(fs+1,m+1,ld);
    mx[vn]=max(mx[fs],mx[fs+1])+val[vn];
   // cout<<vn<<' '<<ls<<' '<<ld<<' '<<mx[vn]<<'\n'; cout.flush();
}

bool check(int lat) {
    //cout<<lat<<'\n';cout.flush();
    for(int i=0; i<DC; ++i) mx[i]=val[i]=0;
    for(int i=0; i<=mxx; ++i) {
        //cout<<i<<'\n';cout.flush();
        for(int j=0; j<x[i].size();++j) {
            gls=x[i][j]; gld=min(gls+lat,5000); vl=1;
            update(1,1,5000);
           // cout<<gls<<' '<<gld<<' '<<mx[1]+val[1]<<'\n';
        }
        //cout<<i<<' '<<mx[1]+val[1]<<'\n';
        int ind=i-lat-1;
        if(ind>=0) for(int j=0; j<x[ind].size(); ++j) {
            gls=x[ind][j]; gld=min(gls+lat,5000); vl=-1;
            update(1,1,5000);
        }
        if(mx[1]+val[1]>=k) {
            //cout<<mx[1]<<'\n';
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("puncte5.in","r",stdin);
    freopen("puncte5.out","w",stdout);
    scanf("%d %d",&n,&k);
    //cout<<n<<' '<<k<<'\n';
    for(int i=1; i<=n; ++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        mxx=max(a,mxx);
        x[a].push_back(b);
    }
   //cout<<check(48)<<'\n';
    int ls=1,ld=5005,m;
    for(;ls<=ld;) {
        m=(ls+ld)>>1;
        //cout<<ls<<' '<<m<<' '<<ld<<'\n';
        if(check(m)) ld=m-1;
        else ls=m+1;
    }
    for(;!check(ls) && ls<=DC;++ls);
    for(;check(ls) && ls>=0;--ls);
    printf("%d",ls+1);
    return 0;
}
