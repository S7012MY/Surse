#include <iostream>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if(n<=k) {
		cout<<2;
		return 0;
	}
	n*=2;
	if(0==n%k) cout<<n/k;
	else cout<<((n/k)+1);
	return 0;
}