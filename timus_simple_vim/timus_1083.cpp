#include <iostream>
#include <string>
using namespace std;

int n,k,rez=1;
string s;

int main()
{
	cin>>n;
	getline(cin,s);
	for(int i=0; i<s.size(); ++i) if(s[i]=='!') ++k;
	for(int m=n%k; m<=n; m+=k) rez*=m;
	cout<<rez;
	return 0;
}
