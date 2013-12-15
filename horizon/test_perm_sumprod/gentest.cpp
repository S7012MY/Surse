#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	 ofstream g("in.in");
	srand(time(NULL));
	int n=10;
	g<<n<<'\n';
	for(int i=1; i<=n; ++i) g<<rand()%100<<' ';
}
