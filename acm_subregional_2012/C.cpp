#include <iostream>
#include <queue>
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int> per;

int t,n,m;
long long dmin[55][55],bst[(1<<17)][20],r=(1LL<<40);
queue<pair<per,long long> > c;

int count(int nr) {
  if(nr==0) return 0;
  int r=0;
  do {
    r++;
  }while(nr&=(nr-1));
  return r;
}

int main() {
  for(cin>>t;t;--t) {
    cin>>n>>m;
    ++n;
    r=(1LL<<40);
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) dmin[i][j]=(1<<30);
    for(int i=0; i<(1<<n); ++i) for(int j=0; j<=n; ++j) bst[i][j]=(1<<30);
    for(int i=0; i<m; ++i) {
      int a,b,c;
      cin>>a>>b>>c;
      dmin[a][b]=dmin[b][a]=c;
    }
    for(int k=0; k<n; ++k) for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
      dmin[i][j]=min(dmin[i][j],dmin[i][k]+dmin[k][j]);
    bst[0][0]=1;
    --n;
    for(c.push(mp(mp(0,0),0));c.size();c.pop()) {
      int state=c.front().x.x,lst=c.front().x.y;
      cout<<state<<' '<<lst<<'\n';
      if(count(state)==n-1) {
        r=min(r,c.front().y);
      }
      for(int i=0; i<n; ++i) if(!(state&(1<<i)) && bst[state|(1<<i)][i+1]>bst[state][lst]+dmin[lst][i+1]) {
        cout<<i<<' ';
        bst[state|(1<<i)][i+1]=bst[state][lst]+dmin[lst][i+1];
        c.push(mp(mp((state|(1<<i)),i+1),c.front().y+bst[state|(1<<i)][i+1]));
      }
      cout<<'\n';
    }
    if(r==(1LL<<40)) cout<<-1<<'\n';
    else cout<<r<<'\n';
  }
}
