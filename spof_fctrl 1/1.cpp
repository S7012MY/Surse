#include <iostream>
using namespace std;
/*const int m5[]={0,5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125};

static inline int f(int nr) {
    int rez=0;
    for(int i=1;m5[i]<=nr; ++i )
        rez+=(nr/m5[i]);
    return rez;
}*/

int main()
{
	int t;
	long long n,rez=0;
	cin>>t;
	for(int i=1; i<=t; ++i) {
		cin>>n;
		rez^=n;
	}
	cout<<rez;
	return 0;
}