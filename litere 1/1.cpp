#include <fstream>
using namespace std;

int freq[26],n,rez;

int main()
{
	ifstream f("litere.in");
	ofstream g("litere.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
		char c;
		f>>c;
		++freq[c-'a'];
		for(int j=c-'a'+1; j<26; ++j) rez+=freq[j];
	}
	g<<rez;
	return 0;
}