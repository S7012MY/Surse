#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 10005
using namespace std;

typedef vector<int>::iterator it;
int t,n,rez;
vector<int> gr[DN];
bitset<DN> viz;

static inline void dfs(int &s,int &dst) {
    viz[s]=1;
    if(rez>1) return;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        if(*i==dst)++rez;
        if(rez>1) return;
        if(!viz[*i]) dfs(*i,dst);
    }
}

int main()
{
    ifstream f("input");
    ofstream g("output");
    f>>t;
    for(int k=1; k<=t; ++k) {
        f>>n;
        for(int i=1; i<=n; ++i) gr[i].clear();
        for(int i=1; i<=n; ++i) {
            int c;
            f>>c;
            for(int j=1; j<=c; ++j) {
                int b;
                f>>b;
                gr[i].push_back(b);
            }
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                viz&=0;
                rez=0;
                dfs(i,j);
                if(rez>=2) {
                    g<<"Case #"<<k<<": Yes\n";
                    break;
                }
            }
            if(rez>=2) break;
        }
        cout<<k; cout.flush();
        if(rez<2) g<<"Case #"<<k<<": No\n";
    }
    return 0;
}
