#include <iostream>
#include <algorithm>
#define DN 10005
using namespace std;

int n,k,aib[DN],v[DN],ind[DN],rez,cr=-1;

bool cmp(const int &a, const int &b) {
	return v[a]>v[b];
}

int lsb(int x) {
	return (x&(x-1))^x;
}

void ins(int x) {
	for(int i=x; i<=n; i+=lsb(i)) ++aib[i];
}

int query(int x) {
	int rez=0;
	for(int i=x; i>0; i-=lsb(i)) rez+=aib[i];
	return rez;
}

int main()
{
	cin>>n>>k;
	for(int j=1;j<=k; ++j) {
		for(int i=1; i<=n; ++i) {
			aib[i]=0;
			ind[i]=i;
			cin>>v[i];
		}
		sort(ind+1,ind+n+1,cmp);
		int sc=0;
		for(int i=1; i<=n; ++i) {
			sc+=query(ind[i]);
			ins(ind[i]);
		}
		//cout<<j<<' '<<sc<<'\n';
		if(sc>cr) {
			cr=sc;
			rez=j;
		}
	}
	cout<<rez;
	return 0;
}
