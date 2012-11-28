#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#define DN 205
#define x first
#define y second
using namespace std;

typedef pair<double, double> per;
per p[DN];
int n,sz,bst=2;

double arie(per a,per b,per c) {
    return a.x*b.y+a.y*c.x+b.x*c.y-a.x*c.y-a.y*b.x-c.x*b.y;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i].x>>p[i].y;
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) {
        int c=0;
        for(int k=1; k<=n; ++k) if(arie(p[i],p[j],p[k])==0) ++c;
        bst=max(bst,c);
    }
    cout<<bst;
    return 0;
}
