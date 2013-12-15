#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define DN 3005
using namespace std;

struct cerc {
    long long x,y,r,f;
}c[DN];

bool cmp(const cerc &a,const cerc &b) {
    return a.r<b.r;
}

long long dist(cerc a,cerc b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool incl(cerc a,cerc b) {//b inclus in a
    if(dist(a,b)<=(a.r-b.r)*(a.r-b.r)) return 1;
    return 0;
}

long long n,bst[DN];

int main()
{
    ifstream f("cercuri4.in");
    ofstream g("cercuri4.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>c[i].x>>c[i].y>>c[i].r>>c[i].f;
    }
    sort(c+1,c+n+1,cmp);
    bst[1]=c[1].f;
    for(int i=2;i<=n; ++i) {
        for(int j=i; j>0; --j) if(incl(c[i],c[j]))
            bst[i]=max(bst[i],bst[j]);
        bst[i]+=c[i].f;
    }
    long long rez=0;
    for(int i=1; i<=n; ++i) rez=max(rez,bst[i]);
    g<<rez;
    return 0;
}
