#include <iostream>
#include <fstream>
#include <vector>
#define DN 100005
#define pb push_back
using namespace std;

typedef vector<int>::iterator it;

int n,m,sol[DN*5],sz,ns=1,st[DN*5],ss;
vector<int> gr[DN];

void euler() {
    for(st[++ss]=1;ss;) {
        int s=st[ss];
        if(0==gr[s].size()) {
            sol[++sz]=s;
            --ss;
            continue;
        }
        int n=gr[s].back();
        gr[s].pop_back();
        for(it i=gr[n].begin(); i!=gr[n].end(); ++i) if(*i==s) {
            gr[n].erase(i);
            break;
        }
        st[++ss]=n;
    }
}

int main()
{
    ifstream f("ciclueuler.in");
	ofstream g("ciclueuler.out");
	f>>n>>m;
	for(int i=0; i<m; ++i) {
	    int a,b;
	    f>>a>>b;
	    gr[a].pb(b);
	    gr[b].pb(a);
	    ++st[a]; ++st[b];
	}
	for(int i=1; i<=n; ++i) if(st[i]&1) {
	    g<<"-1";
	    return 0;
	}
	euler();
	for(int i=sz; i>1; --i) g<<sol[i]<<' ';
    return 0;
}
