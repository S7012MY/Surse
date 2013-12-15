//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define DN 1005
//using namespace std;
//
//int t,n,m,k;
//long long aib[DN];
//vector<pair<int,int> > v;
//
//int lsb(int x) {
//  return (x&(x-1))^x;
//}
//
//void update(int i) {
//  for(;i<=m; i+=lsb(i)) ++aib[i];
//}
//
//int query(int i) {
//  int r=0;
//  for(;i;i-=lsb(i)) r+=aib[i];
//  return r;
//}
//
//int main()
//{
//  cin>>t;
//    for(int T=1;T<=t;++T) {
//      cin>>n>>m>>k;
//      v.clear();
//      for(int i=1; i<=m; ++i) aib[i]=0;
//      for(int i=0; i<k; ++i) {
//        int a,b; cin>>a>>b;
//        v.push_back(make_pair(a,b));
//      }
//      sort(v.rbegin(),v.rend());
//      long long r=0;
//      for(int i=0; i<k; ++i) {
//        r+=query(v[i].second-1);
//        update(v[i].second);
//      }
//      cout<<"Test case "<<T<<": "<<r<<'\n';
//    }
//    return 0;
//}
