#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
vector<per> p;
vector<int> s;
int n;

bool cmp(const per &a,const per &b) {
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}

int main()
{
    time_t beg=clock();
    ifstream f("poligon6.in");
    ofstream g("poligon6.out");
    f>>n;
    int r;
    for(int i=1; i<=n; ++i) {
        f>>r;
        for(int j=1; j<r; ++j) {
            int k=sqrt(r*r-j*j);
            if(k*k+j*j==r*r) p.push_back(make_pair(j,k));
        }
    }
    sort(p.begin(),p.end(),cmp);

    double catan=atan2(p[0].y,p[0].x);
    int rc=0;
    for(int i=0; i<p.size(); ++i) {
        if(atan2(p[i].y,p[i].x)==catan) ++rc;
        else {
            s.push_back(rc);
            catan=atan2(p[i].y,p[i].x);
            rc=1;
        }
    }
    g<<p.size()<<'\n'<<s.size()+1<<'\n';
    for(int i=0; i<s.size(); ++i) g<<s[i]<<' ';
    g<<rc;
    cout<<(clock()-beg)/CLOCKS_PER_SEC;
    return 0;
}
