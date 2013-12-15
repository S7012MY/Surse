#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

char in[55],ou[55];
int n,base;

int main() {
	srand(time(NULL));
	for(int i=1; i<=20; ++i) {
		n=0;
		base=rand()%9+2;
		int ncif=rand()%8+1;
		n=rand()%(base-1)+1;
		for(int i=2; i<=ncif; ++i) n=n*10+rand()%base;
		
		sprintf(in,"grader_test%d.in",i);
		sprintf(ou,"grader_test%d.ok",i);
		ofstream f(in);
		ofstream g(ou);
		
		f<<n<<' '<<base;
		
		int rez=0,put=1;
		for(;n; put*=base,n/=10) rez+=((n%10)*put);
		g<<rez;
	}
}
