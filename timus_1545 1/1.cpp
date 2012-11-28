#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> v[26];

int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i) {
		string s;
		cin>>s;
		v[s[0]-'a'].push_back(s);
	}
	char c;
	cin>>c;
	int l=c-'a';
	for(int i=0; i<v[l].size(); ++i) cout<<v[l][i]<<'\n';
	return 0;
}
