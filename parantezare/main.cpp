#include <fstream>
#include <stack>
#include <string>
#define DN 100005
#define mp make_pair
using namespace std;

stack<pair<char,int> > s;

int n,lft[DN],rgt[DN],m,q;
string v;

int main()
{
    ifstream f("parantezare.in");
    ofstream g("parantezare.out");
    f>>v;
    for(int i=0; i<v.size(); ++i) {
        if('('==v[i]) s.push(mp(v[i],i));
        else if(')'==v[i]) {
            lft[i]=s.top().second;
            rgt[s.top().second]=i;
            s.pop();
        }
    }
    f>>m;
    for(int i=0; i<m; ++i) {
        f>>q;
        g<<max(lft[q],rgt[q])<<' ';
    }
    return 0;
}
