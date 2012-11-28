#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#define DN 1005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;//le tin pe dos

int n,m,cnt;
per p[DN];
map<int,int> norm;

int main() {
	ifstream f("tri2.in");
	ofstream g("tri2.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
		f>>p[i].y>>p[i].x;
		if(norm.find(p[i].y)==norm.end()) norm[p[i].y]=++cnt;
	}
	sort(p+1,p+n+1);
	for(int i=1; i<=n; ++i) {
		
	}
	return 0;
}