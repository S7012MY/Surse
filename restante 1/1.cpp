#include <fstream>
#include <string>
#include <algorithm>
#define DN 36000
using namespace std;

int n,rez,v[DN]={1};
string s[DN];

int main()
{
	ifstream f("restante.in");
	ofstream g("restante.out");
	f>>n;
	for(int i=0; i<n; ++i) {
		f>>s[i];
		sort(s[i].begin(),s[i].end());
	}
	sort(s,s+n);
	for(int i=1; i<n; ++i) {
		if(s[i]==s[i-1]) v[i]=v[i-1]=0;
		else v[i]=1;
	}
	for(int i=0; i<n; ++i) if(v[i]) ++rez;
	g<<rez;
	return 0;
}