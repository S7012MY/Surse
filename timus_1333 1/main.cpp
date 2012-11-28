#include <iostream>
#include <cmath>
#define x first
#define y second
using namespace std;

typedef pair<double,double> per;

per p[15];
double r[15];
int n,bune,gen;

double dist(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i].x>>p[i].y>>r[i];
    for(double i=0; i<=1; i+=0.001) for(double j=0; j<=1; j+=0.001) {
        ++gen;
        for(int k=1; k<=n; ++k) if(dist(p[k].x,p[k].y,i,j)<=r[k]) {
            ++bune;
            break;
        }
        //cout<<i<<' '<<j<<' '<<bune<<'\n';
    }
    cout<<((double)bune*100.0)/gen;
    return 0;
}
