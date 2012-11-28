#include <fstream>
#define DN 1000005
using namespace std;

int n,k,p[DN],c[DN],f[2][DN],sol;

int main() {
    ifstream fi("ephie.in");
    ofstream g("ephie.out");
    fi>>n>>k;
    for(int i=1; i<=n; ++i) fi>>p[i]>>c[i];
    for(int i=1; i<=n; ++i) {
		int pre=(i&1)^1;
		int act=pre^1;
        f[act][0]=f[pre][0]-c[i];
        for(int j=1; j<=k; ++j)
            f[act][j]=max(f[pre][j-1]+p[i],f[pre][j]-c[i]);
		if(i>=k) sol=max(sol,f[act][k]);
    }
    g<<sol;
}
