//#include <iostream>
//#include <string>
//#include <cstdio>
//using namespace std;
//
//string s,a,rez,pat;
//int t,n;
//
//string trans(int sh, int m) {
//  string r;
//  for(int i=0; i<s.size(); i+=m) {
//    int cd=min((int)s.size()-1,i+m-1);
//    for(;cd>=i;--cd) r+=s[cd];
//  }
//  for(int i=0; i<r.size(); ++i) r[i]=(r[i]-'A'-sh+26)%26+'A';
//  return r;
//}
//
//int main() {
//  //freopen("input.txt","r",stdin);
//  for(cin>>t;t;--t) {
//    s=""; cin>>n;
//    for(;s.size()<n;) {
//      cin>>a;
//      s.append(a);
//    }
//    cin>>pat;
//   // cout<<trans(1,6);while(1);
//    int ok=0;
//    for(int s=1; s<26 && !ok; ++s) for(int m=5; m<21; ++m) {
//      rez=trans(s,m);
//      if(rez.find(pat)!=string::npos) {
//        cout<<s<<' '<<m<<'\n'; ok=1;
//        break;
//      }
//    }
//    if(!ok) cout<<"Crib is not encrypted.\n";
//  }
//}
