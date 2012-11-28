#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#define DN 120005
#define x first
#define y second
using namespace std;

typedef pair<double, double> per;
int n;
per p[DN];

bool id(const per &a,const per &b, const per &c) {
	double dy=a.y-b.y,
		dx=b.x-a.x,
		z=a.x*b.y-b.x*a.y;
	double ec=dy*c.x+dx*c.y+z;
	return (ec<0);
}

int main()
{
	ifstream f("terenuri.in");
	ofstream g("terenuri.out");
	int m;
	f>>n>>m;
	for(int i=1; i<=n; ++i) f>>p[i].x>>p[i].y;
	sort(p+1,p+n+1);
	vector<per> st;
	st.push_back(p[1]); st.push_back(p[2]);
	for(int i=3; i<=n; ++i) {
		for(;st.size()>1 && id(st[st.size()-2],st[st.size()-1],p[i]); st.pop_back());
		st.push_back(p[i]);
	}
	for(int i=n-1; 0<i; --i) {
		for(;st.size()>1 && id(st[st.size()-2],st[st.size()-1],p[i]); st.pop_back());
		st.push_back(p[i]);
	}
	st.pop_back();
	g<<st.size()<<'\n';
	//for(int i=0; i<st.size(); ++i) g<<fixed<<setprecision(6)<<st[i].x<<' '<<st[i].y<<'\n';
	return 0;
}