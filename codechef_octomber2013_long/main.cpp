//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//int det(int x1,int y1,int x2,int y2,int x3,int y3) {
//  return abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
//}
//
//int amin=(1<<30),amax=-(1<<30),imin,imax;
//
//int main()
//{
//    int n;cin>>n;
//    for(int i=1;i<=n;++i) {
//      int x1,y1,x2,y2,x3,y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
//      int a=det(x1,y1,x2,y2,x3,y3);
//      if(a<=amin) {
//        amin=a;
//        imin=i;
//      }
//      if(a>=amax) {
//        amax=a;
//        imax=i;
//      }
//    }
//    cout<<imin<<' '<<imax<<'\n';
//    return 0;
//}
