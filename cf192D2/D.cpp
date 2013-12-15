//#include <iostream>
//#include <queue>
//#define x first
//#define y second
//using namespace std;
//
//typedef pair<int,int> per;
//
//int n,m,dst[1005][1005],d2[1005][1005];
//int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
//string s[1005];
//
//int check(int x,int y) {
//  return(x>=0 && y>=0 && x<n && y<m && s[x][y]!='T');
//}
//
//void bfs(int x,int y,int dst[1005][1005]) {
//  queue<per> c;
//  dst[x][y]=1;
//  for(c.push(make_pair(x,y));c.size();c.pop()) {
//    for(int d=0; d<4; ++d) {
//      int ii=c.front().x+dx[d],jj=c.front().y+dy[d];
//      if(check(ii,jj) && dst[ii][jj]==0) {
//        dst[ii][jj]=dst[c.front().x][c.front().y]+1;
//        c.push(make_pair(ii,jj));
//      }
//    }
//  }
//}
//
//int main() {
//  cin>>n>>m;
//  for(int i=0; i<n; ++i) cin>>s[i];
//  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(s[i][j]=='S') bfs(i,j,dst);
//  int df,r=0;
//  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(s[i][j]=='E') {
//    df=dst[i][j];
//    bfs(i,j,d2);
//  }
//  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if('0'<s[i][j] && s[i][j]<='9' && d2[i][j]<=df && d2[i][j]!=0) r+=s[i][j]-'0';
//  //for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cerr<<dst[i][j];
//  cout<<r;
//}
