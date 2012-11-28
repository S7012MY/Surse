#include <iostream>
using namespace std;

int main()
{
	int m,n,p;
	cin>>m>>n;
	p=m*n;
	if(p&1) cout<<"[second]=:]";
	else cout<<"[:=[first]";
	return 0;
}