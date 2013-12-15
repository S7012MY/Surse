//#include <iostream>
//#include <vector>
//#define DN 1035
//#define x first
//#define y second
//using namespace std;
//
//typedef pair<int,int> per;
//
//int n,d[DN][DN];
//
//void rez() {
//  cin>>n;
//  for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) cin>>d[i][j];
//  int r=d[1][2]-1;
//  for(int i=3; i<=n; ++i) {
//    int dmin=(1<<30);
//    for(int j=i-1; j>1; --j) dmin=min(dmin,d[j][i]+d[1][i]-d[1][j]);
//    r+=dmin/2-1;
//  }
//  cout<<r<<'\n';
//}
//
//int main() {
//  int t;
//  for(cin>>t;t--;) {
//    rez();
//  }
//}
