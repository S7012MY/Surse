#include <fstream>
#include <vector>
#define DN 10005
#define DM 30005
using namespace std;

typedef vector<int>::iterator it;

int n,m,sz,d[DN],viz[DN];
vector<int>gr[DN];

ifstream f("drumuri.in");
ofstream g("drumuri.out");

void dfs(int s, int f) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i] && d[*i]) dfs(*i,s);
    if(0==d[s]%2) f=0;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(d[*i] && *i!=f) {
        g<<*i<<' '<<s<<' ';
        --d[*i];
        for(;;) {
            ++i;
            if(d[*i] && *i!=f) {
                g<<*i<<'\n';
                --d[*i];
                break;
            }
        }
    }
    d[s]%=2;
}

int main()
{
    f>>n>>m;
    for(int i=0; i<m; ++i) {
        int x,y;
        f>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
        ++d[x]; ++d[y];
    }
    if(m%2) {
        g<<0;
        return 0;
    }
    g<<"1\n";
    for(int i=1; i<=n; ++i) if(!viz[i]) dfs(i,i);
    return 0;
}
