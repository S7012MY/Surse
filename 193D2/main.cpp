//#include <iostream>
//#define LL long long
//#define DN 200005
//using namespace std;
//
//int n,k;
//LL v[200005],sp[200005];
//LL sm1[DN],pm1[DN],mx,pmx;
//
//int main()
//{
//    cin>>n>>k;
//    for(int i=1; i<=n; ++i) {
//      cin>>v[i];
//      sp[i]=sp[i-1]+v[i];
//    }
//    for(int i=k; i<=n; ++i) {
//      LL spx=sp[i]-sp[i-k];
//      sm1[i]=sm1[i-1]; pm1[i]=pm1[i-1];
//      if(sm1[i]<spx) {
//        sm1[i]=spx;
//        pm1[i]=i-k+1;
//      }
//     // cerr<<i<<' '<<pm1[i]<<'\n';
//    }
//    for(int i=k+k; i<=n; ++i) {
//      LL spx=sp[i]-sp[i-k];
//      if(sm1[i-k]+spx>mx) {
//        mx=sm1[i-k]+spx;
//        pmx=i-k+1;
//      }
//      //cerr<<i<<' '<<sp[i]<<'\n';
//    }
//    cout<<pm1[pmx-1]<<' '<<pmx;
//    return 0;
//}
