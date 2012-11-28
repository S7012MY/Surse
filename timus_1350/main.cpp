#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;
int n,m,k,ni,found[105];
string z;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>z;
        s.insert(z);
    }
    cin>>k;
    cin>>ni;
    for(int i=1; i<=ni; ++i) {
        cin>>z;
        s.erase(z);
    }
    for(int i=1; i<=k; ++i) {
        cin>>ni;
        for(int j=1; j<=ni; ++j) {
            cin>>z;
            if(s.find(z)!=s.end()) ++found[i];
        }
    }
    cin>>m;
    for(int i=1; i<=k; ++i) {
        if(s.size()-found[i]<m) cout<<"NO\n";
        else if(found[i]) cout<<"MAYBE\n";
        else cout<<"YES\n";
        //cout<<found[i]<<' ';
    }
    return 0;
}
