/*#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define x first
#define y second
#define LL long long
#define DN 55
#define DNN 55*55
using namespace std;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
typedef set<int>::iterator is;

int n;
double x[DN],y[DN],X[DN],Y[DN];
double minx=999999,miny=999999,maxx=-1,maxy=-1;
vector<double> vx,vy;
double dx[]={0.1,0,-0.1,0},dy[]={0,0.1,0,-0.1};

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) {
      cin>>x[i]>>y[i]>>X[i]>>Y[i];
      minx=min(x[i],minx); miny=min(y[i],miny);
      maxx=max(X[i],maxx); maxy=max(Y[i],maxy);
      for(int d=0; d<4; ++d) {
        vx.push_back(x[i]+dx[d]); vx.push_back(X[i]+dx[d]);
        vy.push_back(y[i]+dy[d]); vy.push_back(Y[i]+dy[d]);
      }
    }
    if(maxx-minx!=maxy-miny) {
      cout<<"NO";
      return 0;
    }
    //cerr<<minx<<' '<<miny<<' '<<maxx<<' '<<maxy<<'\n';
    for(int i=0; i<vx.size(); ++i) if(vx[i]>=minx && vx[i]<=maxx) for(int j=0; j<vy.size(); ++j) if(vy[j]>=miny && vy[j]<=maxy) {
      int ok=0;
      for(int k=1; k<=n; ++k) if(vx[i]>=x[k] && vx[i]<=X[k] && vy[j]>=y[k] && vy[j]<=Y[k]) ok=1;
      if(!ok) {
        //cerr<<vx[i]<<' '<<vy[j]<<'\n';
        cout<<"NO";
        return 0;
      }
    }

    cout<<"YES";
    return 0;
}
*/
