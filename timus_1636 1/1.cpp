#include <iostream>
using namespace std;

int main()
{
	int t1,t2,cont=0,cc;
	cin>>t1>>t2;
	for(int i=0; i<10; ++i) {
		cin>>cc;
		cont+=cc;
	}
	cc=cont*20;
	if(t1<=t2-cc) cout<<"No chance.";
	else cout<<"Dirty debug :(";
	return 0;
}