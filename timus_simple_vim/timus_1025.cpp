#include <iostream>
#include <algorithm>
#include <cmath>
#define DK 105
using namespace std;

int k,v[DK],rez;

int main() 
{
	cin>>k;
	for(int i=1; i<=k; ++i) cin>>v[i];
	sort(v+1,v+k+1);
	for(int i=1; i<=floor(k/2.0)+1; ++i) rez+=floor(v[i]/2.0)+1;
	cout<<rez;
	return 0;
}
