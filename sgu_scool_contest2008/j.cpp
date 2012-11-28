#include <iostream>
#include <vector>
#include <algorithm>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;

int n,t,tsolve[DN],m,viz[DN],ok,nok[DN];
vector<int> gr[DN],r,st;
vector<pair<int,int> > sol;

void marc(int s) {
    nok[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!nok[*i]) marc(*i);
}

void dfs(int s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i)
        if(viz[*i]) {
            ok=1;
            marc(*i);
        }else dfs(*i);
    st.push_back(s);
}

int main() {
    cin>>n>>t;
    for(int i=1; i<=n; ++i) cin>>tsolve[i];
    cin>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
    }
    for(int i=1; i<=n; ++i) if(!viz[i]) {
        ok=1;
        dfs(i);
    }
    for(int i=st.size()-1; i>=0; --i) if(!nok[st[i]]) sol.push_back(make_pair(tsolve[st[i]],st[i]));
    sol.push_back(make_pair(1<<30,-1));
    sort(sol.begin(),sol.end());
    long long tc=0,pen=0;
    for(int i=0; i<sol.size(); ++i) {
        if(tc*1LL+sol[i].first>t) {
            cout<<i<<' '<<pen<<'\n';
            break;
        }
        tc+=sol[i].first;
        pen+=tc;
        r.push_back(sol[i].second);
    }
    for(int i=0; i<r.size(); ++i) cout<<r[i]<<' ';
    return 0;
}
