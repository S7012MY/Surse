#include <iostream>
#include <string>
using namespace std;

int n,m,dx[]={1,0,-1,0},dy[]={0,-1,0,1},mt[1001][1001];
string res;
char dir[]={'D','L','U','R'};

int main() {
    cin>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) mt[i][j]=1;
    int x,y;
    cin>>x>>y;
    for(;;) {
        int ok=0;
        mt[x][y]=0;
        //cout<<x<<' '<<y<<'\n';
        for(int d=0; d<4; ++d) if(mt[x+dx[d]][y+dy[d]]) {
            res+=dir[d];
            x+=dx[d]; y+=dy[d];
            ok=1;
            break;
        }
        if(!ok) break;
    }
    cout<<res;
    return 0;
}
