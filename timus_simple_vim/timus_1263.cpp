#include <cstdio>
#include <iostream>
using namespace std;

int n,m,fr[100005];
/*
	6....100%
	3....x
*/
int main() 
{
	cin>>n>>m;
	for(int i=0; i<m; ++i) {
		int a;
		cin>>a;
		++fr[a];
	}
	for(int i=1; i<=n; ++i) printf("%.2lf%%\n",(fr[i]*100.0)/m);
	return 0;
}
