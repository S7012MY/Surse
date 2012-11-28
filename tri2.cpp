#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#define DN 1005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;//le tin pe dos

int n,m,cnt,p1,aib[DN],ind[DN];
per p[DN];

inline int lsb(int x) {
	return (x&(x-1))^x);
}

bool cmp(per a,per b) {
}

int main() {
	ifstream f("tri2.in");
	ofstream g("tri2.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
		f>>p[i].x>>p[i].y;
		if(norm.find(p[i].y)==norm.end()) norm[p[i].y]=++cnt;
	for(int i=1; i<=n; ++i) {
		sort(p+1,p+n+1,cmp);
	}
	return 0;
}