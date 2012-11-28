#include <iostream>
using namespace std;

int main()
{
	long long n,rez=0;
	cin>>n;
	for(int i=0; i<=n; ++i) {
		long long cate=(n*(n+1))/2LL-(i*(i-1))/2LL;//se reduc
		rez+=cate+i*(n-i+1LL);
		//cout<<rez<<'\n';
	}
	cout<<rez;
	return 0;
}