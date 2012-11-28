#include <iostream>
#include <fstream>
#include <vector>
#define DN 200005
using namespace std;

typedef vector<int>::iterator it;

int t,n,deg[DN];
vector<int> gr[DN];

int main()
{
    ifstream f("itree.in");
    ofstream g("itree.out");
    for(f>>t;t;--t) {
        f>>n;
        for(int i=0; i<=n; ++i) gr[i].clear(),deg[i]=0;
        for(int i=1; i<n; ++i) {
            int a,b;
            f>>a>>b;
            ++deg[a]; ++deg[b];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        int ok=1;
        for(int i=1; i<=n; ++i) {
            int cnt=0;
            for(it j=gr[i].begin(); j!=gr[i].end(); ++j) if(deg[*j]>1) ++cnt;
            if(cnt>2) ok=0;
        }
        if(ok) g<<"YES\n";
        else g<<"NO\n";
    }
    return 0;
}
