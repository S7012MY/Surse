//#include <iostream>
//#include <algorithm>
//#include <cstdlib>
//#include <cstdio>
//using namespace std;
//
//struct muie {
//  int k,da,db,ind;
//}v[1005];
//
//bool cmp(muie a,muie b) {
//  return a.ind>b.ind;
//}
//
//int n,a,b,r=0;
//
//void imp(int ind,int &a,int d) {
//  int nr=min(v[ind].k,a);
//  v[ind].k-=nr;
//  a-=nr;
//  r+=d*nr;
//}
//
//int main() {
//  freopen("input.in","r",stdin);
//  freopen("output.txt","w",stdout);
//  for(;cin>>n>>a>>b && n!=0;) {
//    r=0;
//    for(int i=0; i<n; ++i) {
//      cin>>v[i].k>>v[i].da>>v[i].db;
//      v[i].ind=abs(v[i].da-v[i].db);
//    }
//    sort(v,v+n,cmp);
//    for(int i=0; i<n; ++i)
//      if(v[i].da<v[i].db) imp(i,a,v[i].da),imp(i,b,v[i].db);
//      else imp(i,b,v[i].db),imp(i,a,v[i].da);
//    cout<<r<<'\n';
//  }
//}
