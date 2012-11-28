#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#define DN 1005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;//le tin pe dos

int n,m,cnt,p1,aib[DN],ind[DN],c[DN][DN],ii[DN];
double tg[DN];
per p[DN];

inline int lsb(int x) {
	return ((x&(x-1))^x);
}

bool c(int a, int b) {
	return p[a]<p[b];
}

bool cmp(int a,int b) {
	return tg[a]<tg[b];
}

void up(int p) {
	for(;p<=n;p+=lsb(p)) ++aib[p];
}

int query(int p) {
	int r=0;
	for(int i=p; i>0; i-=lsb(i)) r+=aib[i];
	return r;
}

bool id(per a,per b,per c) {
	int sum=b.x*c.y+c.x*a.y+a.x*b.y;
	int dif=-a.x*c.y-b.x*a.y-c.x*b.y;
	return (sum+dif)<0LL;
}

int main() {
	ifstream f("tri2.in");
	ofstream g("tri2.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
		f>>p[i].x>>p[i].y;
		ind[i]=i;
	}
	sort(ind+1,ind+n+1,c);
	for(int i=1; i<=n; ++i) {
		memset(aib,0,sizeof(aib));
		for(int j=i+1; j<=n; ++j) {
			ind[j]=j;
			tg[j]=((double)p[ii[j]].y-p[ii[i]].y)/(p[ii[j]].x-p[ii[i]].x);
		}
		sort(ind+i,ind+n+1,cmp);
		for(int j=i+1; j<=n; ++j) {
			c[ii[i]][ii[ind[j]]]=query(ind[j]);
			up(ind[j]);
		}
	}
	f>>m;
	for(int 
	return 0;
}