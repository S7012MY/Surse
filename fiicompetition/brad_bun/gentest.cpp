#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define DN 1000000000
using namespace std;

int n;

int main() {
	ofstream g("brad.in");
	srand(time(NULL));
	n=rand()%DN+1;
	g<<n;
	return 0;
}
