//#include <iostream>
//#include <vector>
//#include <map>
//#include <bitset>
//#include <cstring>
//#define DN 10005
//using namespace std;
//
//typedef vector<int>::iterator it;
//
//map<int,int> h,w;
//vector<int> gr[DN];
//int n,cnt,l[DN],r[DN],ch,cw;
//bitset<DN> viz;
//
//int cupl(int x) {
//  if(viz[x]) return 0;
//  viz[x]=1;
//  for(it i=gr[x].begin(); i!=gr[x].end(); ++i) if(!l[*i]) {
//    l[*i]=x;
//    r[x]=*i;
//    return 1;
//  }
//  for(it i=gr[x].begin(); i!=gr[x].end(); ++i) if(cupl(l[*i])) {
//    l[*i]=x;
//    r[x]=*i;
//    return 1;
//  }
//  return 0;
//}
//
//void ins(int x,map<int,int> &nrm,int &cnt) {
//  if(nrm.find(x)==nrm.end()) nrm[x]=++cnt;
//}
//
//int main() {
//  int t;
//  for(cin>>t;t--;) {
//    cin>>n;
//    ch=cw=0;
//    h.clear();w.clear();
//    cnt=0;
//    memset(l,0,sizeof(l));
//    memset(r,0,sizeof(r));
//    for(int i=0; i<=2*n; ++i) gr[i].clear();
//    for(int i=1; i<=n; ++i) {
//      int x,y; cin>>x>>y;
//      ins(x,h,ch); ins(y,w,cw);
//      gr[h[x]].push_back(w[y]);
//    }
//    for(int ok=1;ok;) {
//      ok=0;
//      viz&=0;
//      for(int i=1; i<=ch; ++i) if(!r[i]) ok|=cupl(i);
//    }
//    int re=0;
//    for(int i=1; i<=ch; ++i) re+=(r[i]!=0);
//    //cerr<<re<<'\n';
//    cout<<re<<'\n';
//  }
//}
