#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 1005
using namespace std;

int n,s,sir[DN],srt[DN*DN],ds,rez;

struct hsk {
    int val,cnt;
} v[600005];

inline int hash(int vl) {
    return (vl&0x0007ffff)^(vl>>19);
}

inline void insert(int vl) {
    int h_vl=hash(vl);
    for(;v[h_vl].val!=vl && v[h_vl].cnt!=0;++h_vl);
    v[h_vl].val=vl; ++v[h_vl].cnt;
}

inline int count(int vl) {
    int h_vl=hash(vl);
    for(;v[h_vl].val!=vl && v[h_vl].cnt!=0;++h_vl);
    //cout<<vl<<' '<<v[h_vl].cnt<<'\n';
    return v[h_vl].cnt;
}

int main()
{
    ifstream f("take5.in");
    ofstream g("take5.out");
    f>>n>>s;
    for(int i=1; i<=n; ++i) f>>sir[i];
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) srt[++ds]=sir[i]+sir[j];
    sort(srt,srt+ds+1);
    sort(sir+1,sir+n+1);
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) for(int k=j+1; k<=n; ++k) {
        int vl=s-sir[i]-sir[j]-sir[k];
        if(vl<0) break;
        int p=lower_bound(srt+1,srt+ds+1,vl)-srt-1;
        for(;srt[p]<vl;++p);
        if(srt[p]==vl) {
            int u=upper_bound(srt+1,srt+ds+1,vl)-srt-1;
            cout<<p<<' '<<u<<'\n';
            for(;srt[u]<=vl && u<ds;++u);
            rez+=(u-p);
            if(u==ds) ++rez;
        }
    }
    g<<rez-ds;
    return 0;
}
