#include <fstream>
using namespace std;

typedef pair<int,int> per;

long long v[2][2],rez;;
int n;

int main() {
	ifstream f("points.in");
	ofstream g("points.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
		int a,b;
		f>>a>>b;
		a&=1; b&=1;
		++v[a][b];
	}
	for(int i=0; i<(1<<6); ++i)  if( (i & 0x30) >> 4 <= (i & 0x0c) >> 2 && (i & 0x0c) >> 2 <= (i & 0x03)){
		int x1=i>>5,y1=(i>>4)&1;
		int x2=(i>>3)&1,y2=(i>>2)&1;
		int x3=(i>>1)&1,y3=i&1;
		int m12=0,m23=0,m13=0;
		if(x1==x2 && y1==y2) m12=1;
		if(x1==x3 && y1==y3) m13=1;
		if(x2==x3 && y2==y3) m23=1;
		//a.x*b.y+a.y*c.x+b.x*c.y-a.x*c.y-a.y*b.x-c.x*b.y;
		if((x1*y2)^(y1*x3)^(x2*y3)^(x1*y3)^(y1*x2)^(x3*y2)) continue;
		long long nrp=0;
		if(m12 && m23 && m13) nrp=(v[x1][y1]*(v[x1][y1]-1)*(v[x1][y1]-2))/6;
		else if(m12) nrp=(v[x1][y1]*(v[x2][y2]-1)*v[x3][y3])/2;
		else if(m23) nrp=(v[x1][y1]*v[x2][y2]*(v[x3][y3]-1))/2;
		else if(m13) nrp=(v[x1][y1]*v[x2][y2]*(v[x3][y3]-1))/2;
		else nrp=v[x1][y1]*v[x2][y2]*v[x3][y3];
		rez+=nrp;
	}
	g<<rez;
	return 0;
}
