#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#define DK 50005
using namespace std;

#define max_c 200000
#define x first
#define y second

pair<double, double> coord[DK];
int n;

double compute(pair<double, double> a, double x) {
	return sqrt((a.x-x)*(a.x-x)+a.y*a.y);
}

double solve(double x) {
	double mx=0.0;
	for(int i=1; i<=n; ++i) {
		mx=max(mx, compute(coord[i], x));
	}
	return mx;
}

double ternarySearch() {
	double st=-max_c, dr=max_c;
   	double target=1e-6;
	while (dr-st>target) {
		double a=(st+dr)/2.0;
		double b=(a+dr)/ 2.0;
		if (solve(a)<solve(b))
			dr=b;
		else
			st=a;
	}
	return st;
}

int main() {
  freopen("balance.in","r",stdin);
  freopen("output.txt","w",stdout);
	for(;;) {
    	cin>>n;
		if (n==0)
			break;
		for(int i=1; i<=n; ++i)
			cin>>coord[i].first>>coord[i].second;
		double rez=ternarySearch();
		cout<<fixed<<setprecision(9)<<rez<<' ';
		cout<<fixed<<setprecision(9)<<solve(rez)<<'\n';
	}
	return 0;
}








