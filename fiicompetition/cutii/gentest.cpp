#include <fstream>
#include <cstdlib>
#include <ctime>
#define DM 20
#define DN 10
#define NR 200
using namespace std;

int main() {
	srand(time(NULL));
	ofstream g("cutii.in");
	int m,n,j=1;
	while(rand()%2 || j>0) {
		m=rand()%DM+1; n=rand()%DN+1;
		g<<m<<' '<<n<<'\n';
		for(int i=1; i<=m; ++i) {
			for(int i=1; i<=n; ++i) g<<rand()%NR<<' ';
			g<<'\n';
		}
		if(j==1) --j;
	}
	return 0;
}
