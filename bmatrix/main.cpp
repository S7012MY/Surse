#include <iostream>
#include <fstream>
#include <cstring>
#define DN 205
using namespace std;

typedef pair<int,int> per;

int n,m,h[DN],sol,x[DN],y[DN],sz;
char mt[DN][DN];

int fa(int x1, int y1, int x2, int y2) {
    sz=0;
    int ret=0;
    memset(h,0,sizeof(h));
    for(int i=x1; i<=x2; ++i) {
        for(int j=y1; j<=y2; ++j) {
            if('0'==mt[i][j]) ++h[j];
            else h[j]=0;
        }

        x[sz=1]=0; y[sz]=1;
        for(int j=y1; j<=y2+1; ++j) {
            ret=max(ret,h[j]);
            int lst=j;
            for(;sz && x[sz]>=h[j];--sz) {
                ret=max(ret,x[sz]*(j-y[sz]));
                lst=y[sz];
            }
            x[++sz]=h[j];
            y[sz]=lst;
        }
    }
    return ret;
}

int main()
{
    ifstream f("bmatrix.in");
    ofstream g("bmatrix.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>mt[i]+1;
    }
    int lm=m/2;
    for(int i=1; i<=lm; ++i) sol=max(sol,fa(1,1,n,i)+fa(1,i+1,n,m));
    lm=n/2;
    for(int i=1; i<=lm; ++i) sol=max(sol,fa(1,1,i,m)+fa(i+1,1,n,m));
    g<<sol;
    return 0;
}
