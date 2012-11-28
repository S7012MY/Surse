#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define DN 75005
using namespace std;

vector<int> gr[DN];
set<int> s;

int n,pr[DN],fr[DN];

int main()
{
    for(;cin>>pr[++n];) ++fr[pr[n]];
    //n;
    for(int i=1; i<=n; ++i) if(!fr[i]) s.insert(i);
    for(int i=1; i<=n; ++i) if(pr[i]!=0){
        gr[pr[i]].push_back(*s.begin());
        gr[*s.begin()].push_back(pr[i]);
        s.erase(s.begin());
        --fr[pr[i]];
        if(!fr[pr[i]]) s.insert(pr[i]);
    }
    for(int i=1; i<=n; ++i) {
        cout<<i<<": ";
        sort(gr[i].begin(),gr[i].end());
        for(int j=0; j<gr[i].size(); ++j) cout<<gr[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
