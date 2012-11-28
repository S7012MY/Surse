#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <tr1/unordered_set>
#define DN 2005
#define x first
#define y second
#define LL long long
#define INF 9999999999
using namespace std;
using namespace tr1;

typedef pair<int, int> per;
typedef unordered_multiset<int>::iterator is;
unordered_multiset<int> b;
int n,m,pmin[DN];
per p[2*DN];
double dmin[DN];
double cst,bd=INF;

double dist(per a, per b) {
    return sqrt(1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y));
}

int main()
{
    ifstream f("retea2.in");
    ofstream g("retea2.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) f>>p[i].x>>p[i].y;
    int bi;
    for(int i=1;i<=m; ++i) {
        f>>p[i+n].x>>p[i+n].y;
        dmin[i]=INF;
        for(int j=1; j<=n; ++j) dmin[i]=min(dmin[i],dist(p[j],p[i+n]));
        if(bd>dmin[i]) {
            bd=dmin[i];
            bi=i;
        }
        b.insert(i);
    }
    for(;b.size();) {
        b.erase(b.find(bi));
        cst+=bd;
        bd=INF;
        for(is i=b.begin(); i!=b.end(); ++i) dmin[*i]=min(dmin[*i],dist(p[bi+n],p[*i+n]));
        for(is i=b.begin(); i!=b.end(); ++i) if(bd>dmin[*i]) {
            bd=dmin[*i];
            bi=*i;
        }
    }
    g<<fixed<<setprecision(6)<<cst;
    cout<<fixed<<setprecision(6)<<cst;
    return 0;
}
