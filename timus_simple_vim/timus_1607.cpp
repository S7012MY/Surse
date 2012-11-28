#include <iostream>
using namespace std;

void fa(int a, int b, int c, int d) {
	if(a>c) {
		cout<<a;
		return;
	}
	a+=b;
	if(a>c) a=c;
	c-=d;
	fa(a,b,c,d);
}

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	fa(a,b,c,d);
	return 0;
}
