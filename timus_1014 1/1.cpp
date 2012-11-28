#include <iostream>
using namespace std;

int pcifre(int nr) {
	int p=1;
	for(;nr;p*=(nr%10),nr/=10);
	return p;
}

int main()
{
	int n;
	cin>>n;
	for(long long i=0; i<=888555555555LL; ++i) {
		if(pcifre(i)==n) {
			cout<<i;
			return 0;
		}
	}
	return 0;
}