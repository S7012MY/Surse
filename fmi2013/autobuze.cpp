#include <iostream>
#include <fstream>
#include <unordered_map>
#define DN 50005
using namespace std;

int n,r,pre[DN],v[DN],sz[DN];
unordered_map<int,int> idx;

inline int find(int x) {
  if(pre[x]==x) return x;
  pre[x]=find(pre[x]);
  return pre[x];
}

void unite(int a,int b) {
  int x=find(a),y=find(b);
  if(sz[x]>sz[y]) pre[y]=x;
  else pre[x]=y;
  if(sz[x]==sz[y]) ++sz[y];
}
//<parsing>
FILE* fin=fopen("autobuze.in","r");
const unsigned maxb=30000192;
char buf[maxb];
unsigned ptr=maxb;

inline unsigned getInt(){
    unsigned nr=0;
    while(buf[ptr]<'0'||'9'<buf[ptr])
        if(++ptr>=maxb)
            fread(buf,maxb,1,fin),ptr=0;
    while('0'<=buf[ptr]&&buf[ptr]<='9'){
        nr=nr*10+buf[ptr]-'0';
        if(++ptr>=maxb)
            fread(buf,maxb,1,fin),ptr=0;
    }
    return nr;
}
//</parsing>
int main() {
  ifstream f("autobuze.in");
  ofstream g("autobuze.out");
  n=getInt();
  for(int i=1; i<=n; ++i) {
    pre[i]=i;
    v[i]=getInt();
    idx[v[i]]=i;
  }
  for(register int i=n; i>=1; --i) {
    for(register int j=v[i]; j<10000005; j+=v[i]) if(idx.find(j)!=idx.end())
      unite(i,idx[j]);
  }
  for(int i=1; i<=n; ++i) if(pre[i]==i) ++r;
  g<<r;
}
