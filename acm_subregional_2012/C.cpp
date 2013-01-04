#include <iostream>
#include <queue>
#define x first
#define y second
#define mp make_pair
#define MULT 1LL<<50
using namespace std;

typedef pair<int,int> per;

int t,n,m;
long long dmin[55][55],bst[(1<<17)][20],r=(1LL<<40);
queue<per> c;

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
    r=(MULT);
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) dmin[i][j]=(MULT);
    for(int i=0; i<(1<<n); ++i) for(int j=0; j<=n; ++j) bst[i][j]=(MULT);
    for(int i=0; i<m; ++i) {
      int a,b,c;
      cin>>a>>b>>c;
      dmin[a][b]=dmin[b][a]=c;
    }
    for(int k=0; k<n; ++k) for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
      dmin[i][j]=min(dmin[i][j],dmin[i][k]+dmin[k][j]);
    bst[0][0]=0;
    --n;
    for(c.push(mp(0,0));c.size();c.pop()) {
      int state=c.front().x,lst=c.front().y;
     // cout<<state<<' '<<count(state)<<' '<<lst<<' '<<bst[state][lst]<<'\n';
      int ram=n-count(state);
      if(count(state)==n) {
        r=min(r,bst[state][lst]);
      }
      for(int i=0; i<n; ++i) {
        if(!(state&(1<<i)) && bst[state|(1<<i)][i+1]>bst[state][lst]+ram*1LL*dmin[lst][i+1]) {
          bst[state|(1<<i)][i+1]=bst[state][lst]+ram*1LL*dmin[lst][i+1];
          c.push(mp((state|(1<<i)),i+1));
        }
      }
    }
    if(r==(MULT)) cout<<"-1";
    else cout<<r;
    if(t>1) cout<<'\n';
  }
}

