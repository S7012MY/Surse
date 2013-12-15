//#include <iostream>
//#include <string>
//#define DN 100005
//using namespace std;
//
//int n,v[DN],st,sm,r;
//string s;
//
//int main () {
//  cin>>n;
//  for(int i=0; i<n; ++i) cin>>v[i];
//  cin>>s;
//  int sig=-1;
//  for(int i=0; i<n; ++i) if(s[i]=='1') sm+=v[i];
//  r=sm;
//  for(int i=0; i<n; ++i) {
//    if(s[i]=='1') {
//      sm-=v[i];
//      r=max(r,st+sm);
//    }
//    st+=v[i];
//  }
//  cout<<r;
//}
//
