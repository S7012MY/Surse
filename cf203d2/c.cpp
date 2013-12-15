#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define DN 1000005
#define x first
#define y second
#define LL long long
using namespace std;

typedef pair<int,int> per;
typedef vector<int>::iterator it;
typedef set<int>::iterator is;

int n,v[DN],r;
string s;
vector<per> op;

int cmp(per a,per b) {
  if(a.x==b.x) return abs(a.y)<abs(b.y);
  return abs(a.x)<abs(b.x);
}

int main()
{
  cin>>n;
  for(int i=0; i<n; ++i) {
    int a,b;
    cin>>a>>b;
    swap(a,b);
    op.push_back(make_pair(a,b));
  }
  sort(op.begin(),op.end(),cmp);
  for(int i=0; i<n; ++i) {
   int a=op[i].x,b=op[i].y;

    if(a>0) ++r;
    else if(a<0) ++r;
    if(b>0) ++r;
    else if(b<0)++r;

    ++r;

    if(a>0) ++r;
    else if(a<0) ++r;
    if(b>0) ++r;
    else if(b<0) ++r;
    ++r;
  }
  cout<<r<<'\n';
  for(int i=0; i<n; ++i) {
    int a=op[i].x,b=op[i].y;

    if(b>0) cout<<"1 "<<b<<" R\n";
    else if(b<0) cout<<"1 "<<-b<<" L\n";
    if(a>0) cout<<"1 "<<a<<" U\n";
    else if(a<0) cout<<"1 "<<-a<<" D\n";

    cout<<"2\n";

    if(a>0) cout<<"1 "<<a<<" D\n";
    else if(a<0) cout<<"1 "<<-a<<" U\n";
    if(b>0) cout<<"1 "<<b<<" L\n";
    else if(b<0) cout<<"1 "<<-b<<" R\n";
    cout<<"3\n";
  }
    return 0;
}
