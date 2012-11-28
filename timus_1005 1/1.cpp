#include <iostream>
#include <algorithm>
#define BIT(n, i) ((n >> i) & 1)
using namespace std;

int n,dmin,dc,v[25];

int main()
{
	cin>>n;
	for(int i=0; i<n; ++i) {
		cin>>v[i];
		dmin+=v[i];
	}
	int lim=1<<n,s1,s2;
	for(int i=0; i<lim; ++i) {
		s1=s2=0;
		for(int j=0; j<n; ++j) 
			if( BIT(i, j) ) s1+=v[j];
			else s2+=v[j];
		if(s1<s2) swap(s1,s2);
		dmin=min(dmin,s1-s2);
	}
	cout<<dmin;
	return 0;
}