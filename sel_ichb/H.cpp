#include <iostream>
#include <string>
#define DN 100005
using namespace std;

long long n,v[DN],vmax,nc;


int main() {
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        vmax=max(vmax,v[i]);
    }
    for(int i=1; i<=n; ++i) {
        if(v[i]==vmax) continue;
        for(int x=v[i];x<=vmax; x<<=1,++nc);
        --nc;
    }
    cout<<vmax+nc<<'\n';
    if(vmax+nc<=1000) {
        for(int i=1; i<=n; ++i) {
            int rc=0;
            for(int x=v[i];x<=vmax; x<<=1,++rc);
            --rc;
            for(int j=1; j<=rc; ++j) cout<<"science mission to the planet "<<i<<'\n';
        }
        for(int i=0; i<vmax; ++i) cout<<"flying mission\n";
    }
    return 0;
}
