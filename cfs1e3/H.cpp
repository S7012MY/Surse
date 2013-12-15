#include <iostream>
#include <queue>
#define x first
#define y second
#define DN 105
#define mp make_pair
using namespace std;

int n,m,bst[2][DN][DN][DN];//mutare,cate mai is,cate are A, cate are B

queue<pair<pair<bool,int>,pair<int,int> > > c;

int main() {
  cin>>n>>m;
  for(c.push(mp(mp(0,n),mp(0,0)));!c.empty();c.pop()) {
    int mut=c.front().x.x,n=c.front().x.y;
    int a=c.front().y.x,b=c.front().y.y;
    cout<<mut<<' '<<n<<' '<<a<<' '<<b<<' '<<bst[mut][n][a][b]<<'\n';
    if(!n && (a || b)) {
      if(mut) {
        bst[mut][b][0][0]=max(bst[mut][b][0][0],bst[mut][n][a][b]+a);
        c.push(mp(mp(mut,b),mp(0,0)));
      }else {
        bst[mut][a][0][0]=max(bst[mut][a][0][0],bst[mut][n][a][b]);
        c.push(mp(mp(mut,a),mp(0,0)));
      }
    }
    for(int i=1; i<=min(m,n); ++i) {
      if(!mut) {
        bst[mut^1][n-i][a+i][b]=max(bst[mut^1][n-i][a+i][b],bst[mut][n][a][b]);
        c.push(mp(mp(mut^1,n-i),mp(a+i,b)));
      }else {
        bst[mut^1][n-i][a][b+i]=max(bst[mut^1][n-i][a][b+i],bst[mut][n][a][b]);
        c.push(mp(mp(mut^1,n-i),mp(a,b+i)));
      }
    }
  }
  cout<<max(bst[0][0][0][0],bst[1][0][0][0]);
}
