#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#define DN 10005
#define EPS 1e-8
using namespace std;

int n,k,v[DN];

bool check(long long cn) {
    if(cn==0LL) {
        cout<<"0.00";
        exit(0);
    }
	int cate=0;
	for(int i=0; i<n; ++i) {
		cate+=v[i]/cn;
		if(cate>=k) return 1;
	}
	return 0;
}

int main()
{
	cin>>n>>k;
	double nc;
	for(int i=0; i<n; ++i) {
	    cin>>nc;
	    v[i]=nc*100;
	}
	long long ls=1,ld=2000000000000,m;
	for(;ls<ld;) {
		//cout<<ls<<' '<<m<<' '<<ld<<'\n';
		m=ls+(ld-ls)/2;
		if(m==0LL) {
		    cout<<"0.00";
		    return 0;
		}
		if(check(m)) ls=m+1;
		else ld=m;
	}
	for(;!check(ld);--ld);
	cout<<fixed<<setprecision(2)<<(double)ld/100.0;
	return 0;
}
