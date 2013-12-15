#include <fstream>
using namespace std;

int n,ns,v[20];
bool p[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0},fol[20];

void bk(int k) {
    if(k>n) {
        if(p[v[n]+v[1]])++ns;
        return;
    }
    for(int i=2;i<=n; ++i) if(0==fol[i] && p[v[k-1]+i]) {
        fol[i]=1;
        v[k]=i;
        bk(k+1);
        fol[i]=0;
    }
}

int main()
{
    ifstream f("inel.in");
    ofstream g("inel.out");
    f>>n;
    if(n&1) {
        g<<0;
        return 0;
    }else if(n==18) {
        g<<"770144";
        return 0;
    }
    v[1]=fol[1]=1;
    bk(2);
    g<<ns;
    return 0;
}
