#include <fstream>
#include <iostream>
#define DN 1005
using namespace std;

int n,nr[DN][DN],r;

/*
 *  nr[i][i]=1
 *  nr[i][lst]=(lst-j)*nr[i-3][j]
*/
/*
1 1 2
1 2 2
1 1 3
1 2 3
2 1 3
2 2 3 + inca una
1 3 3
2 3 3
*/

int main() {
	ifstream f("sir23.in");
	ofstream g("sir23.out");
	f>>n;
	for(int i=1; i<=n; ++i) nr[1][i]=nr[2][i]=1;
	for(int i=1; i<=n; ++i) for(int j=1; j<i; ++j) nr[3][i]+=(i-j+1)*nr[1][j];
	for(int i=1; i<=n; ++i) r+=nr[n][i];
	g<<r;
	return 0;
}