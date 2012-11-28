#include <iostream>
#include <vector>
#define DN 1005
using namespace std;

int n,s,nr;
vector<int> gr[DN],sol;

void euler(int s) {
    for(;gr[s].size();) {
        int y=gr[s].back();
        gr[s].pop_back();
        euler(y);
    }
    sol.push_back(s);
}

int main()
{
    cin>>n>>s;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) {
            cin>>nr;
            if(0==nr && i!=j) gr[i].push_back(j);
        }
    euler(s);
    for(int i=sol.size()-1; i>0; --i) cout<<sol[i]<<' '<<sol[i-1]<<'\n';
    return 0;
}
