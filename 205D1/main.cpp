//#include <iostream>
//#include <iomanip>
//#include <cstdlib>
//#include <cmath>
//using namespace std;
//
//int n,nz,nn;
//double x[2005],st,rez=999999999;
//long long sx;
//
//int main()
//{
//    cin>>n;
//    for(int i=0; i<2*n; ++i) {
//      cin>>x[i];
//      x[i]-=int(x[i]);
//      st+=x[i];
//      if(x[i]==0.0) ++nz;
//    }
//    int r=2*n-nz;
//    int smax=min(n,r),smin=0;
//    if(n<r) smin=r-n;
//    for(int x=smin; x<=smax; ++x)
//      rez=min(rez,abs(x-st));
//    cout<<fixed<<setprecision(3)<<rez;
//    return 0;
//}
