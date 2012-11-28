#include <iostream>
using namespace std;

int main()
{
	int k,n,rez=0,nc;
	cin>>k>>n;
	for(int i=0; i<n; ++i) {
		cin>>nc;
		rez+=nc-k;
		if(rez<0) rez=0;
	}
	if(rez<0) cout<<"0";
	cout<<rez;
	return 0;
}