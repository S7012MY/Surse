#include <iostream>
#include <cstdio>
#define DN 200005
using namespace std;

int n,r=0,put[DN][100];

int gcd(int a,int b) {
	for(int c;b;c=a%b,a=b,b=c);
	return a;
}

int main() {
	//freopen("asd.in","r",stdin);
	cin>>n;
	for(int i=1; i<=n; ++i) r+=(1<<gcd(i,n));
	cout<<r/n;
	return 0;
}