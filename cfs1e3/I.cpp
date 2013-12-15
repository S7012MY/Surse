//#include <iostream>
//#include <string>
//#define LL long long
//using namespace std;
//
//LL conv(string s) {
//  LL r=0;
//  for(int i=0; i<s.size(); ++i) {
//    r=r*10+s[i]-'0';
//  }
//  return r;
//}
//
//LL rev(LL a,LL b) {
//  LL r=0;
//  for(int i=1;i<=b;r=r*10+a%10,a/=10,++i);
//  return r;
//}
//
//int main() {
//  string s,r;
//  //cout<<rev(1001,5);
//  for(;cin>>s;) {
//    LL nr=conv(s),rnr=conv(s);
//    if(nr==0) break;
//    //cout<<rev(10,2);
//    for(;nr!=rev(nr,s.size());++nr);
//    cout<<nr-rnr<<'\n';
//  }
//}
