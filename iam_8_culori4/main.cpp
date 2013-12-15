#include <iostream>
#include <fstream>
#include <cstring>
#define LL long long
#define DN 10
using namespace std;

int n,nr[DN][DN][10],r=1,cine[DN][DN],cnt,cacat[DN*DN];
char m[DN][DN];

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

void fi(int i, int j) {
    cine[i][j]=cnt;
    for(int d=0; d<4; ++d) {
        int ii=i+dx[d],jj=j+dy[d];
        if(ii>0 && ii<=n && jj>0 && jj<=n && !cine[ii][jj] && '?'==m[ii][jj]) fi(ii,jj);
    }
}

int main()
{
    ifstream f("culori4.in");
    ofstream g("culori4.out");
    for(int i=0; i<=10; ++i) for(int j=0; j<=10; ++j) for(int c=0; c<6; ++c) nr[i][j][c]=1;
    f>>n;
    for(int i=1; i<=n; ++i) f>>m[i]+1;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if('?'==m[i][j]) {
        for(int c=1; c<6; ++c) {
            int a=1,b=1;
            if(m[i-1][j]=='?') {
                a=0;
                for(int c2=1; c2<6; ++c2) a+=nr[i-1][j][c];
            }
            if(m[i][j-1]=='?') {
                b=0;
                for(int c2=1; c2<6; ++c2) b+=nr[i][j-1][c];
            }
            nr[i][j][c]=a*b;
            cout<<i<<' '<<j<<' '<<c<<' '<<nr[i][j][c]<<'\n';
        }
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(!cine[i][j] && '?'==m[i][j]) {
        ++cnt;
        fi(i,j);
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if( '?'==m[i][j]) {
        for(int c=1; c<6; ++c) cacat[cine[i][j]]=nr[i][j][c];
    }
    for(int i=1; i<=cnt; ++i) r*=cacat[i];
    g<<r;
    return 0;
}
