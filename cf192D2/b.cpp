//#include <iostream>
//#include <string>
//#include <set>
//#include <map>
//#include <vector>
//#define DN 1000005
//using namespace std;
//
//int n,m,nt[1005][1005],d[DN],ker,mt[1005][1005];
//vector<int> a,b;
//
//int main() {
//  cin>>n>>m;
//  for(int i=0; i<m; ++i) {
//    int a,b;
//    cin>>a>>b;
//    ++d[a]; ++d[b]; nt[a][b]=nt[b][a]=1;
//  }
//  for(int i=1; i<=n; ++i) if(!d[i]) ker=i;
//  for(int i=1; i<=n; ++i) if(i!=ker) {a.push_back(i); b.push_back(ker);}
//  cout<<a.size()<<'\n';
//  for(int i=0; i<a.size(); ++i) cout<<a[i]<<' '<<b[i]<<'\n';
//}
