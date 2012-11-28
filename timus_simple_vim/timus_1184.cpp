#include <iostream>
#include <iomanip>
#include <cmath>
#define DN 10005
#define EPS 1e-8
using namespace std;

int n,k;
double v[DN];

bool check(double cn) {
	int cate=0;
	for(int i=0; i<n; ++i) {
		cate+=floor(v[i]/cn);
		if(cate>=k) return 1;
	}
	return 0;
}

int main()
{
	cin>>n>>k;
	for(int i=0; i<n; ++i) cin>>v[i];
	double ls=0,ld=2000000000,m;
	for(;ld-ls>=EPS;) {
		//cout<<ls<<' '<<m<<' '<<ld<<'\n';
		m=ls+(ld-ls)/2.0;
		if(check(m)) ls=m;
		else ld=m;
	}
	//for(;!check(ld);--ld);
	cout<<fixed<<setprecision(2)<<(double)ls;
	return 0;
}
