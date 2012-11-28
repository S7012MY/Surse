#include <iostream>
#define DG 100005
#define DN 105
using namespace std;

int gt,pos[DG],n,g[DG],fol[DN],cf[DG];

int main()
{
    cin>>gt>>n;
    pos[0]=1;
    for(int i=1; i<=n; ++i) {
        cin>>g[i];
        for(int j=gt; j>=0; --j) if(pos[j]) {
            if(!pos[j+g[i]]) cf[j+g[i]]=i;
            pos[j+g[i]]+=pos[j];
        }
    }
    if(0==pos[gt]) cout<<0;
    else if(pos[gt]>1) cout<<-1;
    else {
        for(;gt;) {
            fol[cf[gt]]=1;
            gt-=g[cf[gt]];
        }
        for(int i=1; i<=n; ++i) if(!fol[i]) cout<<i<<' ';
    }
    return 0;
}
