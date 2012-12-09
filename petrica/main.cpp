#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <cstring>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;

int n,p[DN],marc[DN],cnt,n1,n2;
vector<int> gr[DN];
bitset<DN> viz;

void mrc(int s) {
    marc[s]=cnt;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!marc[*i]) {
        if(*i!=n1 && *i!=n2) mrc(*i);
    }
}

int main()
{
    ifstream f("petrica.in");
    ofstream g("petrica.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>p[i];
    for(int i=1; i<n; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for(n1=1; n1<n; ++n1) for(n2=n1+1; n2<=n; ++n2) {
        memset(marc,0,sizeof(marc));
        cnt=0;
        for(int i=1; i<=n; ++i) if(!marc[i]) {
            ++cnt;
            mrc(i);
        }
        cout<<n1<<' '<<n2<<'\n';
        for(int i=1; i<=n; ++i) cout<<marc[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
