#include <iostream>
using namespace std;

int n,fr[10];

int main() {
	cin>>n;
	int cn=n;
	if(0==n) {
		cout<<10;
		return 0;
	}
	for(int i=9; i>1; --i) for(;0==n%i;) {
		++fr[i];
		n/=i;
	}
	if(cn==1) cout<<1;
	else if(cn==0) cout<<10;
	else if(n!=1) cout<<-1;
	else
		for(int i=2; i<=9; ++i) for(;fr[i];--fr[i]) cout<<i;
	return 0;
}
