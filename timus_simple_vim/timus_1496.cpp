#include <iostream>
#include <string>
#include <set>
using namespace std;

int n;
set<string> ceAm,rez;
string s;

int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>s;
		if(ceAm.find(s)==ceAm.end()) {
			ceAm.insert(s);
			continue;
		}
		rez.insert(s);
	}
	for(set<string>::iterator is=rez.begin(); is!=rez.end(); ++is)
		cout<<*is<<'\n';
	return 0;
}
