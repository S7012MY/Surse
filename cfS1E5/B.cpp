//#include <iostream>
//#include <vector>
//#include <bitset>
//#define DN 10005
//using namespace std;
//
//typedef vector<int>::iterator it;
//
//int t,m,n,l[DN],r[DN];
//bitset<DN> viz;
//vector<int> gr[DN];
//
//int dfs(int s) {
//  if(viz[s]) return 0;
//  viz[s]=1;
//  for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(-1==l[*i]) {
//    l[*i]=s;
//    r[s]=*i;
//    return 1;
//  }
//  for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(dfs(l[*i])) {
//    l[*i]=s;
//    r[s]=*i;
//    return 1;
//  }
//  return 0;
//}
//
//int main() {
//  for(cin>>t;t--;) {
//    cin>>m>>n;
//    for(int i=0; i<n; ++i) l[i]=r[i]=-1,gr[i].clear();
//    for(int i=0; i<m; ++i) {
//      int a,b;cin>>a>>b;
//      gr[i].push_back(a);
//      gr[i].push_back(b);
//    }
//    for(int ok=1;ok;) {
//      ok=0; viz&=0;
//      for(int i=0; i<n; ++i) if(r[i]==-1) ok|=dfs(i);
//    }
//    int c=0;
//    for(int i=0; i<n; ++i) if(r[i]!=-1) ++c;
//    if(c==m) cout<<"successful hashing\n";
//    else cout<<"rehash necessary\n";
//  }
//}
