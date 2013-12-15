#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;

int n,l,m,lg,bun[605][30];
long long nr[305][605];
vector<string> v;
string inp,s;

int main() {
 // freopen("input.txt","r",stdin);
 // freopen("output.txt","w",stdout);
  for(;;) {
    cin>>n>>l>>m;
    if(n==0 && l==0 && m==0) break;
    map<string,int> vf,rev;
    for(int i=0; i<m; ++i) {
      cin>>s;
      for(int i=0; i<s.size(); ++i) s[i]=toupper(s[i]);
        if(vf.find(s)==vf.end()) vf[s]=1;
        else ++vf[s];
        rev[s]=v.size();
        v.push_back(s);
        lg=s.size();
        //cerr<<s<<' '<<rev[s]<<'\n';
        s.clear();
    }
   // cerr<<'\n';
    for(int i=0; i<m; ++i) for(int c=0; c<n; ++c) {
      string r=v[i].substr(1); r+=c+'A';
     // cerr<<r<<' ';
      if(vf.find(r)!=vf.end()) bun[i][c]=rev[r]+1;
      else bun[i][c]=0;
    }
    for(int i=0; i<=l; ++i) for(int j=0; j<m; ++j) nr[i][j]=0;
    for(int i=0; i<m; ++i) nr[lg][i]=vf[v[i]];
    for(int i=lg; i<l; ++i) for(int j=0; j<m; ++j) {
      for(int c=0; c<n; ++c) if(bun[j][c]){
        nr[i+1][bun[j][c]-1]+=nr[i][j];
      }
     // nr[i][j]=0;
    }
    long long rez=0;
    for(int i=0; i<m; ++i) rez+=nr[l][i];
    cout<<rez<<'\n';
    v.clear();
    //while(1);
   // for(double i=0; i<=10000000; i+=0.01);
  }
}
