#include <iostream>
#include <fstream>
#define DN 100005
using namespace std;

int n,k,v[DN],rez,lrez,rrez;

int main()
{
    ifstream f("ksecv.in");
    ifstream g("ksecv.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) f>>v[i];
    for(int i=1; i<=n; ++i) {
        int cnt=0,j;
        for(j=i+1; j<=n; ++j) {
            if(v[j]>v[i]) ++cnt;
            if(cnt>k) break;
        }
        --j;
        if(rez<j-i+1) {
            rez=j-i+1;
            lrez=i; rrez=j;
        }
    }
    int l,r;
    g>>l>>r;
    if(l!=lrez || r!=rrez) {printf("gresit\n");while(1);}
    else printf("OK!\n");
    return 0;
}
