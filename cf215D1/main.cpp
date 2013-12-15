//#include <iostream>
//#include <string>
//#include <cstdlib>
//#define DN 100005
//using namespace std;
//
//string s;
//int n,a,b,f1[DN],f2[DN],f3[DN];
//
//int main()
//{
//  cin>>s>>n;
//  for(int i=0; i<s.size(); ++i) {
//    f1[i+1]=f1[i];
//    f2[i+1]=f2[i];
//    f3[i+1]=f3[i];
//    if(s[i]=='x') ++f1[i+1];
//    if(s[i]=='y') ++f2[i+1];
//    if(s[i]=='z') ++f3[i+1];
//  }
//    for(;n--;) {
//      cin>>a>>b;
//      int d=f1[b]-f1[a-1];
//      int e=f2[b]-f2[a-1];
//      int f=f3[b]-f3[a-1];
//
//      if((abs(d-e)>1 || abs(e-f)>1 || abs(d-f)>1) && b-a+1>2) cout<<"NO\n";
//      else cout<<"YES\n";
//    }
//    return 0;
//}
