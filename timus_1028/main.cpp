#include <iostream>
#define lsb(x) (x & -x)
#define DN 32005
using namespace std;

int n,aib[DN],lev[15005];

void update(int l) {
	for(int i=l; i<DN; i+=lsb(i)) ++aib[i];
}

int query(int l) {
	int r=0;
	for(int i=l; 0<i; i-=lsb(i)) r+=aib[i];
	return r;
}

int main(){
	cin>>n;
	//ofstream g("asd.out");
	for(int i=1; i<=n; ++i) {
		int a,b;
		cin>>a>>b;
		++a;
		++lev[query(a)];
        update(a);
	}
	for(int i=0; i<n; ++i) cout<<lev[i]<<'\n';
	return 0;
}
