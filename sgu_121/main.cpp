#include <iostream>
#include <fstream>
#include <vector>
#define DN 105
using namespace std;

typedef vector<int>::iterator it;

int n,deg[DN],viz[DN],ok,lg,cl[DN][DN];
vector<int> gr[DN],gc[DN];

void dfs(int s) {
    ++lg;
    viz[s]=1;
    if(deg[s]!=2) ok=1;
    if(deg[s]&1) {
        gr[0].push_back(s);
        gr[s].push_back(0);
    }

    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
}

void euler(int s,int col) {
    //cout<<s<<' '<<col<<'\n';
    //cout.flush();
    viz[s]=0;
    for(;gr[s].size();) {
        int x=gr[s].back();
        cl[s][x]=cl[x][s]=col;
        gr[s].pop_back();
        for(it i=gr[x].begin();i!=gr[x].end();++i) if(*i==s) {
            gr[x].erase(i);
            break;
        }
        euler(x,3-col);
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int x;
        for(cin>>x;x;cin>>x) {
            gr[i].push_back(x);
            gc[i].push_back(x);
            ++deg[i];
        }
    }
    for(int i=1; i<=n; ++i) if(!viz[i]) {
        ok=lg=0;
        dfs(i);
        if(!ok && (lg&1)) {
            cout<<"No solution";
            return 0;
        }
    }
    viz[0]=1;
    for(int i=0; i<=n; ++i) if(viz[i]) euler(i,1);
    for(int i=1; i<=n; ++i) {
        for(it j=gc[i].begin(); j!=gc[i].end(); ++j) cout<<cl[i][*j]<<' ';
        cout<<"0\n";
    }
    return 0;
}
