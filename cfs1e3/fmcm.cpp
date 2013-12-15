//#include <iostream>
//#include <vector>
//#include <bitset>
//#include <queue>
//#include <cstdio>
//#define DN 3050
//#define x first
//#define y second
//#define mp make_pair
//using namespace std;
//
//typedef pair<int,int> per;
//typedef vector<per>::iterator it;
//
//int n,a,b,s,d,cap[DN][DN],fl[DN][DN],pre[DN],dst[DN];
//vector<per> gr[DN];
//bitset<DN> inq;
//
//int bf() {
//  queue<int> c;
//  for(int i=1; i<=n; ++i) {
//    dst[i]=(1<<30); pre[i]=-1;
//  }
//  inq&=0;
//  dst[s]=0;
//  for(c.push(s);c.size(); c.pop()) {
//    int fr=c.front();
//    inq[fr]=0;
//    for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(cap[fr][i->x]>fl[fr][i->x] && dst[i->x]>dst[fr]+i->y) {
//      dst[i->x]=dst[fr]+i->y;
//      pre[i->x]=fr;
//      if(!inq[i->x]) {inq[i->x]=1; c.push(i->x);}
//    }
//  }
//  return dst[d]!=(1<<30);
//}
//
//void add(int x,int y,int a,int b) {
//  cap[x][y]=a;
//  gr[x].push_back(mp(y,b));
//  gr[y].push_back(mp(x,-b));
//}
//
//int main() {
//  freopen("fmcm.in","r",stdin);
//  freopen("fmcm.out","w",stdout);
//  int m;
//  cin>>n>>m>>s>>d;
//  for(int i=1; i<=m; ++i) {
//    int a,b,c,d;
//    cin>>a>>b>>c>>d;
//    add(a,b,c,d);
//  }
// // cout<<"aici";
//    long long cmin=0;
//    for(;bf();) {
//      int fc=(1<<30);
//      for(int i=d; i!=s; fc=min(fc,cap[pre[i]][i]-fl[pre[i]][i]),i=pre[i]);
//      for(int i=d; i!=s; fl[pre[i]][i]+=fc,fl[i][pre[i]]-=fc,i=pre[i]);
//      cmin+=1LL*dst[d]*fc;
//      //cerr<<cmin<<' ';
//    }
//    cout<<cmin<<'\n';
//}
//
