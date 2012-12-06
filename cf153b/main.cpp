#include <iostream>
#include <cstdlib>
#define DN 105
using namespace std;

int n,k,p[DN],q[DN],f[DN],np[DN];

void fa(int k) {
    for(;k;) {
        for(int i=1; i<=n; ++i) np[i]=q[p[i]];
        for(int i=1; i<=n; ++i) {
            p[i]=np[i];
            //cout<<p[i]<<' ';
        }
        //cout<<'\n';
        --k;
        int ok=1;
        for(int i=1; i<=n; ++i) if(p[i]!=f[i]) ok=0;
        if(ok && (k%2)==0) {
            cout<<"YES";
            exit(0);
        }
    }
}

int main()
{
    cin>>n>>k;
    if(n==1) {
        cout<<"NO";
        return 0;
    }
    for(int i=1; i<=n; ++i) {
        cin>>q[i];
        p[i]=i;
    }
    int ok=1;
    for(int i=1; i<=n; ++i) {
        cin>>f[i];
        if(i!=f[i])ok=0;
    }
    fa(k);
    if(ok) {
        cout<<"NO";
        return 0;
    }
    for(int i=1; i<=n; ++i) np[q[i]]=i;
    for(int i=1; i<=n; ++i) {
        q[i]=np[i];
        p[i]=i;
    }

    fa(k);
    cout<<"NO";
    return 0;
}
