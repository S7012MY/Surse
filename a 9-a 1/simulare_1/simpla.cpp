#include <fstream>
#include <algorithm>
using namespace std;

int n,s[1005];

int main()
{
	ifstream f("simpla.in");
	ofstream g("simpla.out");
	f>>n;
	for(int i=1; i<=n; ++i) f>>s[i];
	sort(s+1,s+n+1)
	g<<s[1]<<' ';
	for(int i=2; i<=n; ++i) if(s[i]!=s[i-1]) g<<s[i]<<' ';
	return 0;
}
