//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define x first
//#define y second
//#define inf (1<<30)
//using namespace std;
//
//typedef pair<int,int> per;
//
//int t,n,r;
//per p[20005];
//
//bool cmp(per a,per b) {
//  if(a.x==b.x) return a.y<b.y;
//  return a.x>b.x;
//}
//
//int main() {
//  for(cin>>t;t--;) {
//    cin>>n; r=0;
//    for(int i=0; i<n; ++i) cin>>p[i].x>>p[i].y;
//    sort(p,p+n,cmp);
//    vector<int> v;
//    v.push_back(inf);
//    for(int i=0; i<n; ++i) {
//      int pz=lower_bound(v.begin(),v.end(),p[i].y+1)-v.begin();
//      if(pz==v.size()-1) {
//        ++r;
//        v.push_back(inf);
//      }
//      v[pz]=p[i].y;
//    }
//    cout<<r<<'\n';
//  }
//  return 0;
//}
