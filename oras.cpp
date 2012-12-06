#include <fstream>
using namespace std;

int n;
string m[205];

int main() {
	ifstream f("oras.in");
	ofstream g("oras.out");
	f>>n;
	if(n==4) {
		g<<-1;
		return 0;
	}
	int i=3;
	if(n&1) {
		m[0]="010";
		m[1]="001";
		m[2]="100";
	}else {
		m[0]="011100";
		m[1]="001110";
		m[2]="000101";
		m[3]="000011";
		m[4]="101001";
		m[5]="110000";
		i=6;
	}
	for(int i=0; i<n; ++i) m[i].resize(n);
	for(;i<n; i+=2) {
		for(int j=0; j<i; ++j) m[j][i]=m[i+1][j]='1';
		m[i][i+1]='1';
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j)
			if(m[i][j]!='1') g<<'0';
			else g<<'1';
		g<<'\n';
	}
	return 0;
}