#include <iostream>
#define DN 100005
using namespace std;

int n,k,si[4*DN];

void build(int vn=1,int ls=1,int ld=n) {
	if(ls==ld) {
		++si[vn];
		return;
	}
	int fs=vn<<1,m=(ls+ld)>>1;
	build(fs,ls,m); build(fs+1,m+1,ld);
	si[vn]=si[fs]+si[fs+1];
}

void er(int ce,int vn=1,int ls=1,int ld=n) {
	if(ls==ld) {
		--si[vn];
		return;
	}
	int fs=vn<<1,m=(ls+ld)>>1;
	if(ce<=m) er(ce,fs,ls,m);
	else er(ce,fs+1,m+1,ld);
	si[vn]=si[fs]+si[fs+1];
}

int cauta(int ce,int vn=1,int ls=1,int ld=n) {
	if(ls==ld) return ls;
	int fs=vn<<1,m=(ls+ld)>>1;
	if(si[fs]>=ce) return cauta(ce,fs,ls,m);
	return cauta(ce-si[fs],fs+1,m+1,ld);
}

int main()
{
	cin>>n>>k;
	--k;
	int ram=n,lst=1;
	build();
	for(int i=1; i<=n; ++i) {
		int poz=(lst+k)%ram;
		if(poz==0) poz=ram;
		poz=cauta(poz);
		cout<<poz<<' ';
		//cout<<lst<<' ';
		er(poz);
		--ram;
		lst=poz;
	}
	return 0;
}
