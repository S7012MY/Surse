#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

set<string> s;
int y,n,q,c;
string inp,ds;

int main()
{
    cin>>y>>n>>q;
    cin.get();
    for(int i=1; i<=n; ++i) {
        getline(cin,inp);
        ds.clear();
        for(int i=0; i<inp.size() && inp[i]!='#'; ++i) ds+=tolower(inp[i]);
        if(s.find(ds)==s.end()) ++c,s.insert(ds);
        cout<<inp<<' '<<c<<'\n';
        if(c==q+1) {
          //  cout<<inp;
            return 0;
        }
    }
    return 0;
}
