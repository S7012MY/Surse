#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#define DN 105
#define x first
#define y second
using namespace std;

typedef double ud;
typedef pair<ud, ud> per;
int n;
per p[DN];

ud dist(per a, per b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}



int main()
{
	ud sx,sy,dmax;
	dmax=0;
	cin>>n;
	for(int i=1; i<=n; ++i) {
	    cin>>p[i].x>>p[i].y;
	    dmax=max(dmax,dist(make_pair(0,0),p[i]));
    }
	cout<<fixed<<setprecision(9)<<0<<' '<<0<<' '<<dmax;
	return 0;
}
