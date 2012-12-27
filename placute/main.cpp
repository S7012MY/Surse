#include <iostream>
#include <fstream>
#include <set>
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,pair<int,int> > per;
typedef set<per,greater<per> >::iterator is;

int n,k,lst=-1,rez,fr[1005],g[100005],c[100005];
set<per,greater<per> > s;

int main()
{
    ifstream f("placute.in");
    ofstream go("placute.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) {
      f>>g[i]>>c[i];
      ++fr[c[i]];
    }
    for(int i=1; i<=n; ++i) s.insert(mp(g[i],mp(fr[c[i]],c[i])));
    for(;!s.empty();) {
      int ok=0;
      for(is i=s.begin(); i!=s.end(); ++i) if(i->y.y!=lst) {
        ok=1;
        //scout<<i->x<<' '<<i->y<<'\n';
        lst=i->y.y;
        rez+=i->x;
        s.erase(i);
        break;
      }
      if(!ok) break;
    }
    go<<rez;
    return 0;
}
