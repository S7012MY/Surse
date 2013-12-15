#include <fstream>
#include <set>
#include <algorithm>
#include <bitset>
#define DN 805
using namespace std;

typedef multiset<int>::iterator it;
multiset<int> s;
int n,m,q,mt[DN][DN],v[DN*DN];
bitset<DN> el[DN];
it pm;

void er(int el) {
    if(el==*pm) {
        it sters=pm;
        if(s.size()&1) --pm;
        else ++pm;
        s.erase(sters);
    }else {
        s.erase(s.find(el));
        if(el<*pm) {
            if(s.size()&1) ++pm;
        }else {
            if(!(s.size()&1)) --pm;
        }
    }
}

int main()
{
    ifstream f("amedie.in");
    ofstream g("amedie.out");
    f>>n>>m>>q;
    int cnt=0;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        ++cnt;
        f>>mt[i][j];
        v[cnt]=mt[i][j];
        s.insert(v[cnt]);
    }
    sort(v+1,v+cnt+1);
    int si;
    if(cnt&1) si=v[cnt/2+1];
    else si=v[cnt/2];
    pm=s.find(si);
    for(int i=1; i<=q; ++i) {
        char op;
        f>>op;
        if('L'==op) {
            int l;
            f>>l;
            for(int j=1; j<=m; ++j) if(!el[l][j]) {
                el[l][j]=1;
                //cout<<mt[l][j]<<' '<<*pm<<'\n';
                er(mt[l][j]);
            }
        }else if('C'==op) {
            int c;
            f>>c;
            for(int i=1; i<=n; ++i) if(!el[i][c]) {
                el[i][c]=1;
                //cout<<mt[i][c]<<' '<<*pm<<'\n';
                er(mt[i][c]);
               // cout<<*pm<<'\n';
            }
        }else g<<*pm<<'\n';
    }
    return 0;
}
