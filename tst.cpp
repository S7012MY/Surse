#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

struct drum{
  int lst,sz,cst;
  int fol[32];
};

int n=-1,dmin[3005];

void ins(queue<drum> &c,drum fr,int nxt) {
  if(nxt<2 || nxt>2000) return;
  drum next=fr;
  ++next.cst;
  if(next.cst==dmin[nxt]) {
    next.fol[++next.sz]=next.lst=nxt;
    c.push(next);
  }
  if(dmin[nxt]>next.cst) {
    dmin[nxt]=next.cst;
    next.fol[++next.sz]=next.lst=nxt;
    c.push(next);
  }
}

int main() {
  for(int i=2; i<=1000; ++i) dmin[i]=(1<<30);
  queue<drum> c;
  drum fr; fr.sz=0; fr.lst=1; fr.cst=0; fr.fol[++fr.sz]=1;
  for(c.push(fr);c.size(); c.pop()) {
    fr=c.front();
    for(int i=1; i<=fr.sz; ++i) {
      ins(c,fr,fr.lst+fr.fol[i]);
      ins(c,fr,fr.lst-fr.fol[i]);
    }
  }
  while(1) {
    cin>>n;
    if(n==0) break;
    cout<<dmin[n]<<'\n';
  }
  return 0;
}
