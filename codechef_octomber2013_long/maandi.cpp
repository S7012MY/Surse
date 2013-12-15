//#include <iostream>
//using namespace std;
//
//int ok(int x){
//  for(;x;x/=10) if(x%10==4 || x%10==7) return 1;
//  return 0;
//}
//
//int main() {
//  int t;
//  for(cin>>t;t--;) {
//    int n; cin>>n;
//    int cnt=0;
//    for(int i=2; i*i<=n; ++i) if(n%i==0) cnt+=ok(i)+ok(n/i);
//    if(ok(n)) ++cnt;
//    cout<<cnt<<'\n';
//  }
//}
