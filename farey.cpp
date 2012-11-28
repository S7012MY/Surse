#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 40005
#define EPS 0.000000001
using namespace std;

int n,k,phi[DN],nrf,a[DN],b[DN],c[DN];

int cmmdc (int a, int b) {
    while (b) {
        int aux=a;
        a=b;
        b=aux%b;
    }
    return a;
}

bool cmp(const int &i, const int &j) {
	return (double)a[i]/(double)b[i]<=(double)a[j]/(double)b[j];
}

int euler(double lim) {
	int rez=0;
	for(int i=2; i<=n; ++i) phi[i]=i*lim-EPS;
	for(int i=2; i<=n; ++i) {
		rez+=phi[i];
		for(int j=i+i; j<=n; j+=i) phi[j]-=phi[i];
	}
	return rez;
}

int main()
{
	ifstream f("farey.in");
	ofstream g("farey.out");
	f>>n>>k;
	//cb
	int ls=2,ld=n,m;
	for(;ls<ld;) {
		m=(ls+ld)/2;
		int fs=euler((double)(m-1)/n),fd=euler((double)m/n);
		if(fs<k && fd>=k) {
		    ls=ld=m;
		    break;
		}
		if(fd<k) ls=m+1;
		else ld=m-1;
	}
	m=ls-1;
	//generez fractii
	for(int i=2; i<=n; ++i) {
		int j=(int)((double)((m+1)*i-1)/n);
		if((double)j/i<(double)m/n || cmmdc(i,j)>1) continue;
		++nrf; a[nrf]=j; b[nrf]=i; c[nrf]=nrf;
	}
	sort(c+1, c+nrf+1,cmp);
	double val=(double)a[c[1]]/b[c[1]];
    int cat=euler(val);
    g<<a[c[k-cat]]<<' '<<b[c[k-cat]];
	return 0;
}






