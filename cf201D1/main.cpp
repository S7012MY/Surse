//#include <iostream>
//
//using namespace std;
//
//int gcd(int a,int b) {
//  for(int c;b;c=a%b,a=b,b=c);
//  return a;
//}
//
//int x[105];
//
//int main()
//{
//  int n;
//    cin>>n;
//    int mx=-1;
//    for(int i=1; i<=n; ++i) cin>>x[i];
//    int gc=gcd(x[1],x[2]);
//    for(int i=3; i<=n; ++i) gc=gcd(gc,x[i]);
//    for(int i=1; i<=n; ++i) {
//      x[i]/=gc;
//      mx=max(mx,x[i]);
//    }
//    if((mx-n)&1) cout<<"Alice";
//    else cout<<"Bob";
//    return 0;
//}
