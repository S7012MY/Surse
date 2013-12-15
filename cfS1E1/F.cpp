//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <string>
//#include <cctype>
//#include <cstdio>
//using namespace std;
//
//double prob[500][500],r;
//int n,m,t;
//string v[500];
//
//int fa(int i) {
//  string s=v[i];
//  //cout<<s<<' ';
//  if(s[0]=='L') return i;
//  int nr=0;
//  for(int i=0; i<s.size(); ++i) if(isdigit(s[i])) nr=(nr*10)+s[i]-'0';
//  if(s[0]=='-') return i-nr;
//  return i+nr;
//}
//
//int main() {
//  freopen("input.txt","r",stdin);
//  for(cin>>n;n;--n) {
//    cin>>m>>t;
//    memset(prob,0,sizeof(prob));
//    r=0;
//    for(int i=1; i<=m; ++i) cin>>v[i];
//    v[m+1]="0";
//    prob[0][0]=1;
//    for(int j=0; j<=t; ++j) {
//      for(int i=0; i<m; ++i) {
//        int nxt=fa(i+1),add=1;
//        if(v[i+1][0]=='L') ++add;
//        //cout<<i<<' '<<v[i]<<' '<<fa(i)<<'\n';
//        prob[j+add][nxt]+=0.5*prob[j][i];
//        nxt=fa(i+2); add=1;
//        if(v[i+2][0]=='L') ++add;
//        prob[j+add][nxt]+=0.5*prob[j][i];
//        //cout<<prob[j][i]<<' ';
//      }
//      //cout<<prob[j][m]<<' '<<prob[j][m+1]<<'\n';
//      prob[j+1][m+1]+=prob[j][m];
//      r+=prob[j][m+1];
//    }
//    //cout<<"\n\n";
//    //if(n==4) while (1);
//    if(r>0.5) cout<<"Bet for. ";
//    else if(r==0.5) cout<<"Push. ";
//    else cout<<"Bet against. ";
//    cout<<fixed<<setprecision(4)<<r<<'\n';
//   // while(1);
//  }
//}
