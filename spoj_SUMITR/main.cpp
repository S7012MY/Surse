#include <iostream>
#include <cstring>
#define z for(j=0;j<i;++j)
using namespace std;
int v[105][105],t,n,i,j;
int main() {
    for(cin>>t;t--;) {
        memset(v,0,sizeof(v));
        for(;i<n;++i)z cin>>v[i][j];
        for(--i;0<i;--i) z v[i][j]=max(v[i+1][j],v[i+1][j+1])+v[i][j];
        cout<<**v<<'\n';
    }
    return 0;
}
