#include <iostream>
#include <fstream>
#include <set>
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int> per;
typedef set<per,greater<per> >::iterator is;

int n,k,lst=-1,rez;
set<per,greater<per> > s;

int main()
{
    ifstream f("placute.in");
    ofstream g("placute.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) {
      int g,c;
      f>>g>>c;
      s.insert(mp(g,c));
    }
    for(;!s.empty();) {
      int ok=0;
      for(is i=s.begin(); i!=s.end(); ++i) if(i->y!=lst) {
        ok=1;
        //scout<<i->x<<' '<<i->y<<'\n';
        lst=i->y;
        rez+=i->x;
        s.erase(i);
        break;
      }
      if(!ok) break;
    }
    g<<rez;
    return 0;
}
