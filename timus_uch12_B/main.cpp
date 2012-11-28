#include <iostream>
#include <set>
#define DN 100005
using namespace std;

multiset<int>::iterator is;

int n,S,v[DN],beg,sol[DN],sz,r1;
multiset<int> s;

int main()
{
    cin>>n>>S;
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        s.insert(v[i]);
    }
    for(;s.size();) {
        beg=*s.begin();
        sol[++sz]=beg;
        s.erase(s.begin());
        int req=S-beg+1;
        ++r1;

        is=s.lower_bound(req);
        if(is!=s.end()) {
            sol[++sz]=*is;
            ++r1;
            s.erase(is);
            continue;
        }
        if(s.size()) {
            sol[++sz]=*s.begin();
            s.erase(s.begin());
        }
    }
    cout<<r1<<'\n';
    for(int i=1; i<=n; ++i) cout<<sol[i]<<' ';
    return 0;
}
