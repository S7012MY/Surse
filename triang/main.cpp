#include <fstream>
#include <cmath>
#include <algorithm>
#define DN 1505
#define x first
#define y second
using namespace std;

typedef pair<double,double> per;

int n,rez;
per p[DN];
double r32=sqrt(3.0)/2;

bool cmp(per a, per b) {
    if(fabs(a.x-b.x)<1e-5) {
        if(fabs(a.y-b.y)<1e-5) return 0;
        return a.y<b.y;
    }
    return a.x<b.x;
}

inline int cauta(per c) {
    if(binary_search(p,p+n,c,cmp)) return 1;
    return 0;
}

int main()
{
    ifstream f("triang.in");
    ofstream g("triang.out");
    f>>n;
    for(int i=0; i<n; ++i) f>>p[i].x>>p[i].y;
    sort(p,p+n,cmp);
    for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) {
        per n;
        n.x=(p[i].x+p[j].x)*0.5-r32*(p[j].y-p[i].y);
        n.y=(p[i].y+p[j].y)*0.5+r32*(p[j].x-p[i].x);

        rez+=cauta(n);

        n.x=(p[i].x+p[j].x)*0.5+r32*(p[j].y-p[i].y);
        n.y=(p[i].y+p[j].y)*0.5-r32*(p[j].x-p[i].x);
        rez+=cauta(n);
    }
    g<<rez/3;
    return 0;
}
