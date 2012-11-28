#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#define x first
#define y second
#define DN 1005
using namespace std;

typedef pair<int,int> per;

int n;
per p[2*DN];
double rez,bst[DN][DN];

double arie(per a,per b,per c){
    return 0.5*fabs(a.x*b.y+a.y*c.x+b.x*c.y-a.x*c.y-a.y*b.x-c.x*b.y);
}

int main()
{
    ifstream f("popandai2.in");
    ofstream g("popandai2.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>p[i].x>>p[i].y;
        p[i+n]=p[i];
    }

    for(int i=1; i<=n; ++i) {
        int p1=i+1;
        for(int j=i+2; j<=n; ++j) {
            for(;p1<j && arie(p[p1],p[i],p[j])<=arie(p[p1+1],p[i],p[j]);++p1);
            bst[i][j]=arie(p[p1],p[i],p[j]);
        }
    }

    for(int i=1; i<=n; ++i) {
        int p1=i-1;
        for(int j=i-1; j>0; --j) {
            for(;p1>1 && arie(p[p1],p[i],p[j])<=arie(p[p1-1],p[i],p[j]);--p1);
            rez=max(rez,bst[j][i]+arie(p[p1],p[i],p[j]));
        }
    }
    g<<fixed<<setprecision(1)<<rez;
    return 0;
}
