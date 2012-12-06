#include <fstream>
using namespace std;

int n;
char m[205][205];
const char impar[][]= {
	"010",
	"001",
	"100"
},par[][]={
	"011100",
	"001110",
	"000101",
	"000011",
	"110000"
};


int main() {
	ifstream f("oras.in");
	ofstream g("oras.out");
	f>>n;
	if(n==4) {
		g<<-1;
		return 0;
	}
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) m[i][j]='0';
	if(n&1) {
		