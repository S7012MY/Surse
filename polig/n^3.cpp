#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define DN 105
#define x first
#define y second
using namespace std;

int n,sz,bst[DN][DN];


struct per{
    int x,y,c;
} p[DN];

bool id(const per &a,const per &b, const per &c) {
	//| b.x b.y 1 |
	//| c.x c.y 1 |
	//| a.x a.y 1 |
	int sum=b.x*c.y+c.x*a.y+a.x*b.y;
	int dif=-a.x*c.y-b.x*a.y-c.x*b.y;
	return (sum+dif)>0;
}

bool cmp(const per &a,const per &b) {
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}

int main()
{
    ifstream f("polig.in");
    ofstream g("polig.out");
    f>>n;
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) bst[i][j]=-1;
    for(int i=1; i<=n; ++i)
        f>>p[i].x>>p[i].y>>p[i].c;
    sort(p+1,p+n+1,cmp);
    for(int i=1; i<=n; ++i) for(int j=1; j<i; ++j) if(id(p[0],p[j],p[i])) bst[i][j]=p[i].c+p[j].c;
    for(int i=1; i<=n; ++i) for(int j=1; j<i; ++j)
        for(int k=1; k<j; ++k) if(id(p[k],p[j],p[i])) bst[i][j]=max(bst[i][j],bst[j][k]+p[i].c);
    int rez=0;
    for(int i=1; i<=n; ++i) for(int j=1; j<i; ++j) rez=max(rez,bst[i][j]);
    g<<rez;
    return 0;
}
