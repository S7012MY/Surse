#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>
#define DN 105
using namespace std;

int t,n,k,ma[DN][DN],act[DN][DN],r[DN];
bitset<DN> viz;

bool cupl(int s) {
    if(s==-1) return 1;
    if(viz[s]) return 0;
    viz[s]=1;
    for(int i=1; i<=n;++i) if(ma[s][i] && cupl(r[i])) {
        r[i]=s;
        return 1;
    }
    return 0;
}

int main()
{
    ifstream f("input.txt");
	ofstream g("output.txt");
	f>>t;
	for(int c=1;c<=t;++c) {
	    f>>n>>k;
	    g<<"Case #"<<c<<": ";
	    for(int i=1; i<=n; ++i) for(int j=1; j<=k; ++j) f>>act[i][j];
	    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j) {
	        int ok=1;
	        for(int l=1; l<=k; ++l) if(act[i][l]<=act[j][l]) {
	            ok=0;
	            break;
	        }
	        if(ok) ma[i][j]=1;
	    }
	    memset(r,-1,sizeof(r));
	    int rez=0;
	    for(int i=1; i<=n; ++i) {
	        viz&=0;
	        if(!cupl(i)) ++rez;
	    }
	    memset(ma,0,sizeof(ma));
	    g<<rez<<'\n';
	}
    return 0;
}
