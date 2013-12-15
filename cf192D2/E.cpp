#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;

set<pair<int,int> > s;

int n,m,d[100005],di[100005];

int main() {
  cin>>n>>m;
  srand(time(NULL));
  for(int i=0; i<m; ++i) {
    int a,b;
    cin>>a>>b;
    ++di[a]; ++di[b];
    s.insert(make_pair(min(a,b),max(a,b)));
  }
  for(int i=1; i<=n; ++i) if(n-di[i]-1<di[i]) {
    cout<<-1;
    return 0;
  }
  for(int i=0; i<m; ++i) {
    int iter=0;
    for(;;++iter) {
      int a=rand()%n+1,b=rand()%n+1;
      if(a!=b && d[a]<2 && d[b]<2 && s.find(make_pair(min(a,b),max(a,b)))==s.end()) {
        cout<<a<<' '<<b<<'\n';
        ++d[a]; ++d[b];
        break;
      }
      if(iter>1000000) {
        cout<<-1;
        return 0;
      }
    }
  }
}
