#include <fstream>
#include <bitset>
#define DL 100005
#define DB 125
using namespace std;

bitset<DB> bs[DL];
int n,k,st[DL],ss,el;

bool canUnite(bitset<DB> &a,bitset<DB> b) {
	bitset<DB> rez=a&b;
	if(rez.any()) {
		a|=b;
		return 1;
	}
	return 0;
}

int main()
{
	ifstream f("liste.in");
	ofstream g("liste.out");
	f>>n;
	for(int i=0; i<n; ++i) {
		f>>k;
		for(int j=0; j<k; ++j) {
			f>>el;
			bs[i][el]=1;
		}
		if(i) for(;ss && canUnite(bs[i],bs[st[ss]]);--ss);
		st[++ss]=i;
	}
	g<<ss;
	return 0;
}