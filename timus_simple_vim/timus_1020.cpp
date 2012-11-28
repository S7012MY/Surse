#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double pi=3.1415;

int n;
double r,px[105],py[105];

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
	cin>>n>>r;
	double rez=0;
	for(int i=1; i<=n; ++i) cin>>px[i]>>py[i];
	for(int i=2; i<=n; ++i) rez+=dist(px[i],py[i],px[i-1],py[i-1]);
	rez+=2.0*pi*r+dist(px[n],py[n],px[1],py[1]);
	cout<<fixed<<setprecision(2)<<rez;
	return 0;
}
