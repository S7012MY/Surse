#include <iostream>
#include <fstream>
#include <cstring>
#define DN 2000005
using namespace std;

char a[DN],b[DN];
int n,m,pi[DN],apar[1005],sz;

void fap() {
    for(int i=2,q=0; i<=n; ++i) {
        for(;q && a[i]!=a[q+1];q=pi[q]);
        if(a[i]==a[q+1]) ++q;
        pi[i]=q;
    }
}

int main()
{
    ifstream f("strmatch.in");
    ofstream g("strmatch.out");
    f>>a+1>>b+1;
    n=strlen(a+1);
    m=strlen(b+1);
    fap();
    int s=0;
    for(int i=1,q=0; i<=m; ++i) {
        for(;q && b[i]!=a[q+1]; q=pi[q]);
        if(b[i]==a[q+1]) ++q;
        if(q==n)++s;
        if(q==n && sz<1000)apar[++sz]=i-n;
    }
    g<<s<<'\n';
    for(int i=1; i<=sz; ++i) g<<apar[i]<<' ';
    return 0;
}
