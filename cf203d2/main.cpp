//#include <iostream>
//#include <string>
//#include <set>
//#include <map>
//#include <queue>
//#include <vector>
//#include <cmath>
//#include <cstdlib>
//#include <cstdio>
//#include <algorithm>
//#define DN 1000005
//#define x first
//#define y second
//#define LL long long
//using namespace std;
//
//typedef pair<int,int> per;
//typedef vector<int>::iterator it;
//typedef set<int>::iterator is;
//
//int n,tp[DN],nxt[DN],viz[DN],deg[DN];
//string s;
//vector<int> gr[DN],r,c;
//
//void dfs(int s) {
//  if(!s) return;
//  c.push_back(s);
//  viz[s]=1;
//  if(!viz[nxt[s]] && deg[nxt[s]]==1) dfs(nxt[s]);
//}
//
//int main()
//{
//  cin>>n;
//  for(int i=1; i<=n; ++i) cin>>tp[i];
//  for(int i=1; i<=n; ++i) {
//    cin>>nxt[i];
//    ++deg[nxt[i]];
//  }
//  for(int i=1; i<=n; ++i) if(1==tp[i]) {
//    c.clear();
//    dfs(i);
//    if(c.size()>r.size()) {
//      r.clear();
//      for(it i=c.begin(); i!=c.end(); ++i) r.push_back(*i);
//    }
//  }
//  cout<<r.size()<<'\n';
//  reverse(r.begin(),r.end());
//  for(int i=0; i<r.size(); ++i) cout<<r[i]<<' ';
//    return 0;
//}
