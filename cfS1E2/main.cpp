//#include <iostream>
//#include <string>
//#include <cctype>
//#include <cstring>
//#include <cstdio>
//#include <cstdlib>
//using namespace std;
//
//string s;
//char b[8][8],a[8][8];
//int n,m;
//
//void muta(int i,int j,int dx, int dy,int one) {
//  for(int x=i,y=j;x<8 && y<8 && x>=0 && y>=0; x+=dx,y+=dy) {
//    if(b[x][y] && (x!=i || y!=j)) break;
//    a[x][y]=1;
//    //if(b[i][j]=='q')cout<<x<<' '<<y<<'\n';
//    if(one && (x!=i || y!=j)) break;
//  }
//}
//
//int main()
//{
// // freopen("input.txt","r",stdin);
//    for(;cin>>s;) {
//      n=m=0;
//      memset(b,0,sizeof(b));
//      memset(a,0,sizeof(a));
//      for(int i=0; i<s.size();++i) {
//        if(isdigit(s[i])) m+=s[i]-'0';
//        else if(isalpha(s[i])) {
//          b[n][m]=s[i];
//          ++m;
//        }else if(s[i]=='/') {
//          ++n; m=0;
//        }
//      }
//      for(int i=0; i<8; ++i) for(int j=0; j<8; ++j) if(isalpha(b[i][j])) {
//        a[i][j]=1;
//        if(b[i][j]=='R' || b[i][j]=='r') {
//          muta(i,j,-1,0,0);
//          muta(i,j,0,-1,0);
//          muta(i,j,1,0,0);
//          muta(i,j,0,1,0);
//        }
//        if(b[i][j]=='n' || b[i][j]=='N') {
//          muta(i,j,1,-2,1);
//          muta(i,j,-1,-2,1);
//          muta(i,j,-2,-1,1);
//          muta(i,j,-2,1,1);
//          muta(i,j,-1,2,1);
//          muta(i,j,1,2,1);
//          muta(i,j,2,-1,1);
//          muta(i,j,2,1,1);
//        }
//        if(b[i][j]=='b' || b[i][j]=='B') {
//          muta(i,j,1,1,0);
//          muta(i,j,-1,-1,0);
//          muta(i,j,1,-1,0);
//          muta(i,j,-1,1,0);
//        }
//        if(b[i][j]=='q' || b[i][j]=='Q') {
//          muta(i,j,1,1,0);
//          muta(i,j,-1,-1,0);
//          muta(i,j,1,-1,0);
//          muta(i,j,-1,1,0);
//          muta(i,j,-1,0,0);
//          muta(i,j,0,-1,0);
//          muta(i,j,1,0,0);
//          muta(i,j,0,1,0);
//        }
//        if(b[i][j]=='k' || b[i][j]=='K') {
//          muta(i,j,1,1,1);
//          muta(i,j,-1,-1,1);
//          muta(i,j,1,-1,1);
//          muta(i,j,-1,1,1);
//          muta(i,j,-1,0,1);
//          muta(i,j,0,-1,1);
//          muta(i,j,1,0,1);
//          muta(i,j,0,1,1);
//        }
//        if(b[i][j]=='p') {
//          muta(i,j,1,-1,1);
//          muta(i,j,1,1,1);
//        }
//        if(b[i][j]=='P') {
//          muta(i,j,-1,-1,1);
//          muta(i,j,-1,1,1);
//        }
//      }
//      int l=0;
//      for(int i=0;i<8; ++i) {
//        for(int j=0; j<8; ++j) {
//          //cout<<b[i][j];
//          //if(b[i][j]) cout<<i<<' '<<j<<' '<<b[i][j]<<'\n';
//          if(!a[i][j]) ++l;
//        }
//        //cout<<'\n';
//      }
//      cout<<l<<'\n';
//    }
//    return 0;
//}
