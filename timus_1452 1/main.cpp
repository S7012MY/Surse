#include <iostream>
#include <algorithm>
#include <map>
#include <bitset>
#define MOD 1007
#define DN 10005
using namespace std;

map<int,int> hs[MOD];

bitset<DN> fol;
int n,v[DN],ind[DN],rez,inc,rbun;

bool cmp(const int &a,const int &b) {
    return v[a]<v[b];
}

void ins(int vl,int ind) {
    int u=vl%MOD;
    hs[u][vl]=ind;
}

int find(int vl) {
    int u=vl%MOD;
    if(hs[u].find(vl)!=hs[u].end()) return hs[u][vl];
    return 0;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        ind[i]=i;
        ins(v[i],i);
    }
    sort(ind+1,ind+n+1,cmp);
    for(int i=1; i<=n-rez+1; ++i) {
        for(int j=i+1; j<=n-rez+1;++j) {
            int lg,r=v[ind[j]]-v[ind[i]],act;
            if(r==0) continue;

            long long lst=v[ind[i]]+rez*1LL*r;
            if(lst>1000000000) continue;
            if(!find(lst)) continue;
            int ok=1;

            for(lg=1,act=v[ind[j]];find(act);++lg,act+=r);
            if(lg>rez) {
                rez=lg;
                inc=ind[i];
                rbun=r;
            }
        }
        fol&=0;
    }
    if(rez==0) {
        cout<<"1\n1";
        return 0;
    }
    cout<<rez<<'\n';
    for(int i=inc,act=v[i];find(act);act+=rbun,i=find(act)) cout<<i<<' ';
    return 0;
}
