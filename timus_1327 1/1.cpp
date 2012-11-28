#include <iostream>
using namespace std;

int main()
{
	int a,b,rez=0;
	cin>>a>>b;	
	for(int i=a; i<=b; ++i) if(i&1) ++rez;
	cout<<rez;
	return 0;
}