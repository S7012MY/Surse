//#include <iostream>
//#define DN 100005
//#define LL long long
//using namespace std;
//
//int n,m,lst[DN];
//LL a[DN],b[DN];
//
//long long abs(long long x) {
//  if(x>0) return x;
//  return -x;
//}
//
//LL cst(int i,int x,int y) {
//  return b[y]-b[x]+min(abs(a[i]-b[x]),abs(a[i]-b[y]));
//}
//
//int check(LL cmax) {
//  int x,y=0;
//  if(cmax<0) return 0;
//  for(int i=1;i<=n; ++i) {
//    x=y+1; y=x;
//    for(;cst(i,x,y)<=cmax && y<=m; ++y);
//    for(;cst(i,x,y)>cmax && x<=y; --y);
//    if(y>=m) return 1;
//    //cerr<<r<<' ';
//  }
//  if(y<m) return 0;
//}
//
//int main() {
//  cin>>n>>m;
//  for(int i=1; i<=n; ++i) cin>>a[i];
//  for(int i=1; i<=m; ++i) cin>>b[i];
//  LL ls=0,ld=30000000000LL,m,rez=0;
//  for(;ls<=ld;) {
//    m=ls+(ld-ls)/2LL;
//    if(check(m)) {
//      rez=m;
//      ld=m-1;
//    }else ls=m+1;
//  }
//  for(;check(rez);--rez);
//  if(!check(rez)) ++rez;
//  //cerr<<check(2)<<' '<<check(3)<<' '<<check(4)<<'\n';
//  //cerr<<check(2);
//  cout<<rez;
//}
