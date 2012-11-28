#include <iostream>
#include <queue>
#define mp make_pair
#define DN 1005
#define x first
#define y second
using namespace std;

int n,m,dist[DN][DN],dmax,sx,sy,rez;
char h[DN][DN];
typedef pair<int,int> per;
queue<per> c;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

bool check(int a, int b) {
    return (a>=0 && b>=0 && a<n && b<m && '.'==h[a][b]);
}

void bfs(int a, int b) {
    dist[a][b]=1;
    for(c.push(mp(a,b));c.size(); c.pop()) {
        per fr=c.front();
        for(int d=0;d<4; ++d) {
            int i=fr.x+dx[d],j=fr.y+dy[d];
            if(check(i,j) && 0==dist[i][j]) {
                dist[i][j]=dist[fr.x][fr.y]+1;
                c.push(mp(i,j));
            }
        }
    }
}

int main()
{
    cin>>m>>n;
    for(int i=0; i<n; ++i) cin>>h[i];
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if('.'==h[i][j] && 0==dist[i][j]) bfs(i,j);
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        if(dist[i][j]>dmax) {
            dmax=dist[i][j];
            sx=i;sy=j;
        }
        dist[i][j]=0;
    }
    bfs(sx,sy);
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) rez=max(rez,dist[i][j]);
    cout<<rez-1;
    return 0;
}
