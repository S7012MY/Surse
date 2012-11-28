#include <iostream>
#include <string>
using namespace std;

int c[2];
string a[2];

int main()
{
	cin>>a[0]>>a[1];
	for(int j=0;j<2; ++j)
		for(int i=0; i<4; ++i) c[j]=c[j]*10+a[j][i]-'0';
	int cc=0;
	for(int i=0; i<10000; ++i) {
		if(c[cc]==i) {
			cout<<"yes";
			return 0;
		}
		cc^=1;
	}
	cout<<"no";
	return 0;
}
