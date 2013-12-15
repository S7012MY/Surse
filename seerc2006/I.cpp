#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <cstring>
#define DN 140
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

bitset<DN> inq;
vector<per> gr[DN];
int n,m,pre[DN],cst[DN][DN],cap[DN][DN],fl[DN][DN],dst[DN],s,d;

int bf() {
  queue<int> c;
  for(int i=0; i<=n; ++i) {
    dst[i]=(1<<30); pre[i]=-1;
  }
  inq&=0;
  dst[s]=0;
  for(c.push(s);c.size(); c.pop()) {
    int fr=c.front();
    inq[fr]=0;
    for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(cap[fr][i->x]>fl[fr][i->x] && dst[i->x]>dst[fr]+i->y) {
      dst[i->x]=dst[fr]+i->y;
      pre[i->x]=fr;
      if(!inq[i->x]) {inq[i->x]=1; c.push(i->x);}
    }
  }
  return dst[d]!=(1<<30);
}

void add(int x,int y,int a,int b) {
  cap[x][y]+=a;
  gr[x].push_back(mp(y,b));
  gr[y].push_back(mp(x,-b));
}

int main() {
  for(int t=1;;++t) {
    cin>>n>>m;
    if(n==0) break;
    for(int i=0; i<n; ++i) gr[i].clear();
    memset(cap,0,sizeof(cst));
    s=0; d=n-1;
    for(int i=0; i<m; ++i) {
      int a,b,c;cin>>a>>b>>c;
      add(a,b,1,c);
    }
    cout<<"Instance #"<<t<<": ";
    int ok=1,rez=0;
    for(int i=1;i<3; ++i) {
      if(!bf()) {
        cout<<"Not possible\n";
        ok=0;
        break;
      }
      for(int i=d; i!=s;++cap[pre[i]][i],--cap[i][pre[i]],i=pre[i]);
      rez+=dst[n-1];
    }
    if(ok) cout<<rez;
  }
}
