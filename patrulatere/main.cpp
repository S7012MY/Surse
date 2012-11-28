#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#define DN 260
#define x first
#define y second
#define LL long long
using namespace std;

typedef pair<LL,LL> per;

int n,c[DN][DN];
LL cb[DN][5],rez;
per p[DN];

inline bool id(per a,per b,per c) {
	LL sum=b.x*c.y+c.x*a.y+a.x*b.y;
	LL dif=-a.x*c.y-b.x*a.y-c.x*b.y;
	return (sum+dif)<0LL;
}

//int q()

int main()
{
    ifstream f("patrulatere.in");
    ofstream g("patrulatere.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>p[i].x>>p[i].y;
    sort(p+1,p+n+1);
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) {
        //cate puncte am subsegm i,j
        for(int k=i+1; k<j; ++k) if(id(p[i],p[j],p[k])) ++c[i][j];
        //cout<<p[i].x<<' '<<p[i].y<<", "<<p[j].x<<' '<<p[j].y<<' '<<c[i][j]<<'\n';
        c[j][i]=c[i][j];
    }
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
        for(int k=j+1; k<=n; ++k) {
            //cout<<p[i].x<<' '<<p[i].y<<", "<<p[j].x<<' '<<p[j].y<<", "<<p[k].x<<' '<<p[k].y<<' '<<abs(c[psus][pa]+c[psus][pb]-c[pa][pb])<<'\n';
            if(id(p[i],p[k],p[j])) rez+=c[i][k]-c[i][j]-c[j][k]-1LL;
            else rez+=c[i][j]+c[j][k]-c[i][k];
        }
    cb[0][0]=1;
    for(int i=1; i<=n; ++i) {
        cb[i][0]=1;
        for(int j=1; j<=4; ++j) cb[i][j]=cb[i-1][j-1]+cb[i-1][j];
    }
    cout<<cb[n][4]<<' '<<rez;
    g<<cb[n][4]-rez;
    return 0;
}
