#include <fstream>
#include <vector>
#include <queue>
#define DN 1000005
using namespace std;

int n,k,ssol,pt,rez,bst, p[DN],c[DN];
priority_queue<int,vector<int>, greater<int> > rst;

int main()
{
    ifstream f("ephie.in");
    ofstream g("ephie.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) f>>p[i]>>c[i];
    for(int i=1; i<=k; ++i) {
        pt+=p[i];
        rst.push(p[i]+c[i]);
    }
    rez=pt;
    for(int i=k+1; i<=n; ++i) {
        pt+=p[i];
        rst.push(p[i]+c[i]);
        ssol+=rst.top();
        rst.pop();
        bst=pt-ssol;
        rez=max(rez,bst);
    }
    g<<rez;
    return 0;
}
