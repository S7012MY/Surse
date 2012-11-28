#include <iostream>
#include <vector>
#define DN 10005
using namespace std;

typedef vector<int>::iterator it;
int n,m,a,b,grad[DN],nrm;
vector<int> gr[DN],sol;

void euler(int s) {
    for(;gr[s].size();) {
        int v=gr[s].back();
        gr[s].pop_back();
        euler(v);
    }
    sol.push_back(s);
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>m;
        cin>>a;
        for(int j=1; j<=m; ++j) {
            cin>>b;
            gr[a].push_back(b);
            ++nrm;
            a=b;
        }
    }
    euler(1);
    if(sol.size()==nrm+1) {
        cout<<sol.size()-1<<' ';
        for(int i=sol.size()-1; i>=0; --i) cout<<sol[i]<<' ';
    }
    else cout<<0;
    return 0;
}
