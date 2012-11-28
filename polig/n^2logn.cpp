#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define DN 105
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
int n,sz,c[DN],bst[DN];
per p[DN];
pair<double,per> seg[DN*DN];

int main()
{
    ifstream f("polig.in");
    ofstream g("polig.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>p[i].x>>p[i].y>>c[i];
        bst[i]=c[i];
    }
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) if(i!=j) {
        seg[++sz].x=atan2(p[j].y-p[i].y,p[j].x-p[i].y);
        seg[sz].y.x=i;seg[sz].y.y=j;
    }
    sort(seg+1,seg+sz+1);
    for(int i=1; i<=sz; ++i) bst[seg[i].y.y]=max(bst[seg[i].y.y],bst[seg[i].y.x]+c[seg[i].y.y]);
    g<<bst[0];
    return 0;
}
