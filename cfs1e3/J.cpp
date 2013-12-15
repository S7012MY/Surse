//#include <iostream>
//using namespace std;
//
//int dx[]={-1,-1,-1,0,1,1,1,0};
//int dy[]={-1, 0, 1,1,1,0,-1,-1};
//
//char a[55][55],b[55][55],r[55][55];
//int n,nrm[55][55];
//
//int main() {
//  cin>>n;
//  for(int i=1; i<=n; ++i) cin>>a[i]+1;
//  for(int i=1; i<=n; ++i) cin>>b[i]+1;
//  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
//    for(int d=0; d<8; ++d) {
//      int ii=i+dx[d],jj=j+dy[d];
//      if(a[ii][jj]=='*') ++nrm[i][j];
//    }
//  }
//  int ok=0;
//  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
//    if(b[i][j]=='x') {
//      r[i][j]=nrm[i][j]+'0';
//      if(a[i][j]=='*') ok=1;
//    }else r[i][j]='.';
//  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(a[i][j]=='*' && ok) r[i][j]='*';
//  for(int i=1; i<=n; ++i) cout<<r[i]+1<<'\n';
//}
