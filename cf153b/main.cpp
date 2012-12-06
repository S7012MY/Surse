#include <iostream>
#include <cstdlib>
#define DN 105
using namespace std;

int n,k,p[DN],q[DN],f[DN],np[DN],cnt;
int nxt[2][DN][DN],okn[2][DN];

void precalc() {
    int z[DN];
    for(int i=1; i<=n; ++i) p[i]=i;
    for(int j=1; j<=k; ++j) {
        for(int i=1; i<=n; ++i) nxt[0][j][i]=q[p[i]];
        int ok=1;
        for(int i=1; i<=n; ++i) if(nxt[0][j][i]!=f[i]) ok=0;
        okn[0][j]=ok|okn[0][j-1];
    }
    for(int i=1; i<=n; ++i) np[q[i]]=i;
    for(int i=1; i<=n; ++i) {
        z[i]=np[i];
        p[i]=i;
    }

    for(int j=1; j<=k; ++j) {
        for(int i=1; i<=n; ++i) nxt[1][j][i]=z[p[i]];
        int ok=1;
        for(int i=1; i<=n; ++i) if(nxt[1][j][i]!=f[i]) ok=0;
        okn[1][j]=ok|okn[1][j-1];
    }
}

void fa(int k) {
    int exec=0;
    for(;k;) {
        for(int i=1; i<=n; ++i) np[i]=q[p[i]];
        for(int i=1; i<=n; ++i) {
            p[i]=np[i];
            //cout<<p[i]<<' ';
        }
        //cout<<'\n';
        --k; ++exec;
        int ok=1;
        for(int i=1; i<=n; ++i) if(p[i]!=f[i]) ok=0;
        int u=k-exec;
        if(ok) {
            if(k%2==0 && (u<=0 || !okn[cnt][u])) {
                cout<<"YES";
                exit(0);
            }
            else return;
        }
    }
}

int main()
{
    cin>>n>>k;
    precalc();
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
    ++cnt;
    fa(k);
    cout<<"NO";
    return 0;
}
