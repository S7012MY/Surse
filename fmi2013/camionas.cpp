#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <set>
#include <bitset>
#define x first
#define y second
#define DN 50005
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int n,m,gmax,dm[DN];
vector<per> gr[DN];
set<per> s;
bitset<DN> inq;

//<parsing>
FILE* fin=fopen("camionas.in","r");
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
  ofstream g("camionas.out");
 n=getInt(); m=getInt(); gmax=getInt();
  for(int i=2; i<=n; ++i) dm[i]=n+1;
  for(int i=0; i<m; ++i){
    int a,b,c;
    a=getInt(); b=getInt(); c=getInt();
   // cout<<a<<' '<<b<<' '<<(c>gmax)<<'\n';
    gr[a].push_back(make_pair(b,c<gmax));
    gr[b].push_back(make_pair(a,c<gmax));
  }
  s.insert(make_pair(0,1));
  for(;!s.empty();) {
    int fr=s.begin()->second;
    s.erase(s.begin());
    for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(dm[i->x]>dm[fr]+i->y) {
      dm[i->x]=dm[fr]+i->y;
      s.insert(make_pair(dm[i->x],i->x));
    }
  }
    g<<dm[n];
}
