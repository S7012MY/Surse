//#include <iostream>
//#include <string>
//#include <set>
//#include <map>
//#include <vector>
//#define DN 1000005
//using namespace std;
//
//int n,m,l[22],c[22],a[22][22];
//string s[20];
//
//int main()
//{
//    cin>>n>>m;
//  for(int i=0; i<n; ++i) cin>>s[i];
//  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(s[i][j]=='S') l[i]=c[j]=1;
//  for(int i=0; i<n; ++i) if(!l[i]) for(int j=0; j<m; ++j) a[i][j]=1;
//  for(int j=0; j<m; ++j) if(!c[j]) for(int i=0; i<n; ++i) a[i][j]=1;
//  int r=0;
//  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) r+=a[i][j];
//  cout<<r;
//    return 0;
//}
