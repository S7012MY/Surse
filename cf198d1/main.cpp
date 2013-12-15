//#include <iostream>
//#include <algorithm>
//#define DN 100005
//#define LL long long
//using namespace std;
//
//LL n,v[DN],nr,num,sum,sumdif,sdt;
//
//LL cmmdc(LL a,LL b) {
//  for(LL c;b;c=a%b,a=b,b=c);
//  return a;
//}
//
//int main()
//{
//  //cerr<<cmmdc(12,32);
//    cin>>n; num=n;
//    for(int i=1; i<=n; ++i) {
//      cin>>v[i];
//      sum+=v[i];
//    }
//    sort(v+1,v+n+1);
//    for(int i=2; i<=n; ++i) sumdif+=v[i]-v[1];
//    sdt=sumdif;
//    for(int i=2; i<=n; ++i) {
//      sumdif-=((v[i]-v[i-1])*(n-i+1));
//      sdt+=sumdif;
//    }
//   // cerr<<sdt<<'\n';
//    nr=sum+2*sdt;
//    cout<<nr/cmmdc(nr,num)<<' '<<num/cmmdc(nr,num);
//    return 0;
//}
