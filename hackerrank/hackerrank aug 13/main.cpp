#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#define DN 10005
#define MULT (1<<30)
using namespace std;

multiset<int> b;
set<char> a;
string s,r;
int n,f[30],fig[30][DN],ales[30],nxt[30][DN];

int main() {
    cin>>s;
    reverse(s.begin(),s.end());
    for(int i=0; i<s.size(); ++i) {
      ++f[s[i]-'a'];
      for(int j=0; j<30; ++j) fig[j][i]=f[j];
    }
    for(char c='a'; c<='z'; ++c) {
      f[c-'a']/=2;
      nxt[c-'a'][s.size()]=MULT;
    }
    for(int i=s.size()-1; i>=0; --i)
      for(char c='a'; c<='z'; ++c)
        if(s[i]==c) nxt[c-'a'][i]=i;
        else nxt[c-'a'][i]=nxt[c-'a'][i+1];
    n=s.size()/2;
    int i=-1;
    //returnreturn
    //enrrtu
    for(;r.size()<n;) {
      //cerr<<i<<' ';
      for(char c='a'; c<='z'; ++c) if(ales[c-'a']<f[c-'a']){
        int p=nxt[c-'a'][i+1];
        if(p==(1<<30)) continue;
        int ok=1;
        if(p!=0) for(char k='a'; k<='z'; ++k) if(fig[k-'a'][p-1]-ales[k-'a']>f[k-'a']) {
          ok=0;
          break;
        }
        if(ok) {
          i=p;
          r+=c;
          ++ales[c-'a'];
          break;
        }
      }
    }
    cout<<r;
    return 0;
}
