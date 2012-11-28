#include <iostream>
#define DN 10000
using namespace std;

int n,v[DN],fm,fM;

int main()
{
	cin>>n;
	int ls=999999999,ld=0;
	for(int i=1; i<=n; ++i) {
		cin>>v[i];
		ls=min(ls,v[i]);
		ld=max(ld,v[i]);
	}
	int m;
	for(;ls<ld;) {
		fm=fM=0;
		m=(ls+ld)>>1;
		for(int i=1; i<=n; ++i) 
			if(v[i]<=m) ++fm;
			else ++fM;
		if(fm>fM) ld=m;
		else ls=m+1;
	}
	cout<<ls;
	return 0;
}
