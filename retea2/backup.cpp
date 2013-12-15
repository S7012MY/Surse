#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <tr1/unordered_set>
#define DN 2005
#define x first
#define y second
using namespace std;
using namespace tr1;

typedef pair<int, int> per;
typedef unordered_multiset<int>::iterator is;
unordered_multiset<int> c,b;
int n,m;
per p[2*DN];
double cst;

double dist(per a, per b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    ifstream f("retea2.in");
    ofstream g("retea2.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>p[i].x>>p[i].y;
        c.insert(i);
    }
    for(int i=1;i<=n; ++i) {
        f>>p[i+n].x>>p[i+n].y;
        b.insert(i+n);
    }
    for(;b.size();) {
        double bd=0;
        int ind=-1;
        for(is i=c.begin();i!=c.end(); ++i)
            for(is j=b.begin(); j!=b.end(); ++j) if(dist(p[*i],p[*j])<bd) {
                bd=dist(p[*i],p[*j]);
                ind =*j;
            }
        cst+=bd;
        c.insert(ind);
        is k=b.find(ind);
        b.erase(k);
    }
    g<<fixed<<setprecision(6)<<cst;
    cout<<fixed<<setprecision(6)<<cst;
    return 0;
}
