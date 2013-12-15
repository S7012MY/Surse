#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cassert>
#define DN 6000005
using namespace std;

string inp;
int n,pre[DN];

int getint(string s,int &p) {
  int r=0,semn=1;
  for(;p<s.size() && (!r || isdigit(s[p]));++p) {
    if(isdigit(s[p])) r=r*10+s[p]-'0';
    if(s[p]=='-') semn=-1;
  }
  return r*semn;
}

int find(int el) {
    int i,j;
    for(i=el;i!=pre[i]; i=pre[i]);//cautam un nod care e indreptat spre el
    while(el!=pre[el]) {
        j=pre[el];
        pre[el]=i;
        el=j;
    }
    return i;
}

void unite(int a,int b) {
  if(find(a)==find(b)) return;
  if(rand()%2) pre[find(a)]=find(b);
  else pre[find(b)]=find(a);
}

void con(vector<int> v) {
  int src=v[0],dst=v[1],nnn=max(1,v[2]),ds=max(1,v[3]),ss=v[4];
  for(int i=1; i<=nnn; ++i) {
    unite(src,dst);
    if(src+ss<=n) src+=ss;
    if(dst+ds<=n) dst+=ds;
  }
}

void query(vector<int> v) {
  int a=0,b=0;
  int src=v[0],dst=v[1],nnn=max(1,v[2]),ds=max(1,v[3]),ss=v[4];
  for(int i=1; i<=nnn; ++i) {
    if(find(src)==find(dst)) ++a;
    else ++b;
    if(src+ss<=n) src+=ss;
    if(dst+ds<=n) dst+=ds;
  }
  cout<<a<<" - "<<b<<'\n';
}

int main()
{
  srand(time(NULL));
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for(;!cin.eof();) {
      getline(cin,inp);
      int p=1;
      if(tolower(inp[0])=='d') {
        n=getint(inp,p);
        for(int i=0; i<=n; ++i) pre[i]=i;
        continue;
      }
      vector<int> args;
      for(;p<inp.size();) {
        int x=getint(inp,p);
        args.push_back(x);
      }
      for(;args.size()<5;args.push_back(0));
      if(tolower(inp[0])=='q') query(args);
      else con(args);
    }
    return 0;
}
