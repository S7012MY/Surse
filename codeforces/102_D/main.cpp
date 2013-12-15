#include <iostream>
#include <bitset>
#define DN 1005
using namespace std;

bitset<DN> v[DN];

const int dx[]={-2,-2,-1,-1},dy[]={-1,1,-2,2};
const int ddx[]={-2,-2,-1,-1},ddy[]={-1,1,-2,2};
int n,m;

bool check(int a, int b) {
    if(a>0 && b>0 && a<=n && b<=m) return 1;
    return 0;
}

int main()
{
    int rez=0,rez2=0;
    cin>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        int ok=1;
        //cout<<i<<' '<<j<<":\n";
        for(int d=0; d<4; ++d) {
            int ii=i+dx[d],jj=j+dy[d];
            if(check(ii,jj) && v[ii][jj]) {
                ok=0;
                //cout<<ii<<' '<<jj<<'\n';
            }
        }
        if(ok) {
            v[i][j]=1;
            ++rez;
        }
        //cout<<v[i][j]<<' ';
    }
    for(int i=0; i<=n; ++i) v[i]&=0;
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) {
        int ok=1;
        //cout<<i<<' '<<j<<":\n";
        for(int d=0; d<4; ++d) {
            int ii=j+dy[d],jj=i+dx[d];
            if(check(ii,jj) && v[ii][jj]) {
                ok=0;
                //cout<<ii<<' '<<jj<<'\n';
            }
        }
        if(ok) {
            v[j][i]=1;
            ++rez2;
        }
        //cout<<v[i][j]<<' ';
    }
    cout<<max(rez2,rez);
    //cerr<<' '<<rez<<' '<<rez2;
    return 0;
}
