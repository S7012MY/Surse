#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define DN 505
#define DR 1000
using namespace std;

int n,r,v[2*DN];

int main() {
	ofstream g("arcas.in");
	srand(time(NULL));
	n=rand()%DN+2;
	r=rand()%DR+2*n;
	g<<n<<' '<<r<<'\n';
	for(int i=1; i<=2*n; ++i) v[i]=i;
	//for(;v[1]<=n+1;random_shuffle(v+1,v+2*n+1));
	random_shuffle(v+1,v+2*n+1);
	for(int i=1; i<=2*n; ++i) g<<v[i]<<'\n';
	return 0;
}
