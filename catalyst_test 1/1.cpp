#include <iostream>
using namespace std;

long long f[55]={0,1},n;

int main() {
	cin>>n;
	for(int i=2; i<=n; ++i) f[i]=f[i-1]+f[i-2];
	cout<<f[n];
}