#include <iostream>
#include <fstream>
#include <set>
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,pair<int,int> > per;
typedef set<per,greater<per> >::iterator is;

int n,k,lst=-1,fr[1005],g[100005],c[100005];
long long rez;
set<per,greater<per> > s;
multiset<int,greater<int> > w[1005];

int main()
{
    ifstream f("placute.in");
    ofstream go("placute.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) {
      f>>g[i]>>c[i];
      ++fr[c[i]];
      w[c[i]].insert(g[i]);
    }
    for(int i=1; i<=k; ++i) if(fr[i]){
      s.insert(mp(*w[i].begin(),mp(fr[i],i)));
      w[i].erase(w[i].begin());
      --fr[i];
    }
    for(;!s.empty();) {
      int ok=0;
      for(is i=s.begin(); i!=s.end(); ++i) if(i->y.y!=lst) {
        rez+=i->x;
        //cout<<i->x<<' '<<i->y.x<<' '<<i->y.y<<'\n';
        int cul=i->y.y;
        s.erase(i);
        if(fr[cul]) {
          s.insert(mp(*w[cul].begin(),mp(fr[cul],cul)));
          w[cul].erase(w[cul].begin());
          --fr[cul];
        }
        ok=1;
        lst=cul;
        break;
      }
      if(!ok) break;
    }
    go<<rez;
    return 0;
}
