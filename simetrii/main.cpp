#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

int n;
per a[DN],b[DN],sc[DN],nou;

int main()
{
    ifstream f("simetrii.in");
	ofstream g("simetrii.out");
	f>>n;
	for(int i=0; i<n; ++i) f>>sc[i].x>>sc[i].y;
	for(int i=0; i<n; ++i) f>>b[i].x>>b[i].y;
	sort(b,b+n);
	for(int i=0; i<4; ++i) {

	    for(int i=0; i<n; ++i) a[i]=sc[i];
	    sort(a,a+n);
	    int dx=a[0].x-b[0].x,dy=a[0].y-b[0].y,ok=1;
	    for(int i=0; i<n; ++i) a[i].x-=dx,a[i].y-=dy;

        sort(a,a+n);
	    for(int i=0; i<n; ++i) if(a[i]!=b[i]) ok=0;

	    if(ok) {
	        g<<"2\n1 0 0 "<<i*90<<'\n';
	        g<<"0 "<<dx<<' '<<dy<<'\n';
	        return 0;
	    }

	    for(int i=0; i<n; ++i) {
	        nou.x=-sc[i].y;
	        nou.y=sc[i].x;
	        sc[i]=nou;
	    }
	}
	g<<"-1";
    return 0;
}
