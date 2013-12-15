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
	//| b.x b.y 1 |
	//| c.x c.y 1 |
	//| a.x a.y 1 |
	double sum=b.x*c.y+c.x*a.y+a.x*b.y;
	double dif=-a.x*c.y-b.x*a.y-c.x*b.y;
	return (sum+dif)<0.0;
}

int main()
{
	ifstream f("infasuratoare.in");
	ofstream g("infasuratoare.out");
	f>>n;
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
	for(int i=0; i<st.size(); ++i) g<<fixed<<setprecision(6)<<st[i].x<<' '<<st[i].y<<'\n';
	return 0;
}
