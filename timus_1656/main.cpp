#include <iostream>
#include <algorithm>
using namespace std;

int n,m[10][10],v[100];
int dx[]={-1,0,1,0},
    dy[]={0,1,0,-1};

bool check(int i,int j) {
    if(0<i && 0<j && n>=i && n>=j) return 1;
    return 0;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n*n; ++i) cin>>v[i];
    sort(v+1,v+n*n+1);
    int c=n/2+1,p=n*n;
    m[c][c]=v[p--];
    for(int z=1; z<=n; ++z) {//fixam patratul
        int i=c-z,j=c;
        for(;i<c;++i,++j) if(check(i,j)) m[i][j]=v[p--];
        i=c,j=c+z;
        for(;j>c;--j,++i) if(check(i,j)) m[i][j]=v[p--];
        i=c+z,j=c;
        for(;i>c;--i,--j) if(check(i,j)) m[i][j]=v[p--];
        i=c,j=c-z;
        for(;j<c;--i,++j) if(check(i,j)) m[i][j]=v[p--];
        //cout<<endl;
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) cout<<m[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
