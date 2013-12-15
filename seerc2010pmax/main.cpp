//#include <iostream>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//using namespace std;
//
//int n,m,ic,s=1;
//long long mt[1005][22];
//long double pm;
//
//int main()
//{
// // freopen("asd.in","r",stdin);
//    while(cin>>m>>n) {
//      pm=0; s=1;
//      for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>mt[i][j];
//      for(int i=0; i<n; ++i) {
//        pm+=log(abs(mt[i][0]));
//        if(mt[i][0]<0) s=-s;
//      }
//      ic=0;
//      for(int j=1; j<m; ++j) {
//        long double pc=0; int sc=1;
//        for(int i=0; i<n; ++i) {
//          pc+=log(abs(mt[i][j]));
//          if(mt[i][j]<0) sc=-sc;
//        }
//        if(sc>s || (sc==s && sc==1 && pc>=pm) || (sc==s && sc==-1 && pc<=pm)) {
//          pm=pc; s=sc;
//          ic=j;
//        }
//      }
//      cout<<ic+1<<'\n';
//    }
//    return 0;
//}
