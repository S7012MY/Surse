#include <iostream>
using namespace std;

int n,fr[1005],nr,rez;

int main() {
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>nr;
		++fr[nr];
		if(fr[nr]%4==0) ++rez;
	}
	cout<<rez;
	return 0;
}
