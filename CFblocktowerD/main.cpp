#include <iostream>
#include <vector>
#define DN 505
using namespace std;

int n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1},pre[DN][DN];
char mt[DN][DN];
vector<char> t;
vector<int> x,y;

int ok(int i,int j) {
  return (i>=0 && j>=0 && i<n && j<m);
}

void dfs(int a,int b) {
  mt[a][b]='B';
  t.push_back('B'); x.push_back(a); y.push_back(b);
  for(int d=0; d<4; ++d) {
    int ii=a+dx[d],jj=b+dy[d];
    if(ok(ii,jj) && mt[ii][jj]=='.') {
      pre[ii][jj]=d;
      dfs(ii,jj);
    }
  }
  for(int d=0; d<4; ++d) {
    int ii=a+dx[d],jj=b+dy[d];
    if(ok(ii,jj) && mt[ii][jj]=='B' && pre[ii][jj]==d) {
      t.push_back('D'); x.push_back(ii); y.push_back(jj);
      t.push_back('R'); x.push_back(ii); y.push_back(jj);
    }
  }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; ++i) cin>>mt[i];
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(mt[i][j]=='.')
      dfs(i,j);
    cout<<t.size()<<'\n';
    for(int i=0; i<t.size(); ++i) cout<<t[i]<<' '<<x[i]+1<<' '<<y[i]+1<<'\n';
    return 0;
}
