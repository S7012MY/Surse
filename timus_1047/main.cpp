#include <iostream>
#include <iomanip>
#include <cmath>
#define eps 1e-9
#define N n
#define DN 3005
using namespace std;

int n;
double c[DN],a[DN];

int main()
{
	cin>>n;
	cin>>a[0]>>a[n+1];
	for(int i=1; i<=n; ++i) cin>>c[i];
	double ls=-2000,ld=2000,m;
	for(;ls-ld<eps;) {
	    m=(ls+ld)/2.0;
		a[1]=m;
		//cout<<a[1]<<' ';
		for(int i=2;i<=N;++i)a[i]=2*(a[i-1]+c[i-1])-a[i-2];
		double x=2*(a[N]+c[N])-a[N-1];
		if(fabs(a[N+1]-x)<eps) {
			cout<<fixed<<setprecision(2)<<m;
			return 0;
		}
		if(a[N+1]-x<eps) ld=m;
		else ls=m;
	}
	return 0;
}
