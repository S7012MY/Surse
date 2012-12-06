#include <fstream>
#define DN 1005
using namespace std;

int n,nr[DN][DN];

/*
 *  nr[i][i]=1
 *  nr[i][lst]=nr[i-3][j]
*/

int main() {
	ifstream f("sir23.in");
	ofstream g("sir23.out");
	f>>n;
	for(int i=1; i<=n; ++i) nr[1][i]=nr[2][i]=1;
	for(int i=4; i<=n; ++i) for(int lst=1; lst<=n; ++lst) {
		for(int j=1; j<=lst; ++j) for(int k=1; k<=lst; ++k) nr[i][lst]=nr[i-2][j]*nr[i-3];
	}
	for(int i=1; i<=n; ++i)
}