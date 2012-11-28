#include <iostream>
#include <string>
#include <set>
using namespace std;

int n,rez;
set<string> ss;
string s;

int main()
{
	cin>>n;
	cin.get();
	for(int i=0; i<n; ++i) {
		getline(cin,s);
		if(ss.find(s)!=ss.end()) ++rez;
		ss.insert(s);
	}
	cout<<rez;
}
