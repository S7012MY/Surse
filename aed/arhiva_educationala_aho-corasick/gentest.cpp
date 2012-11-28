#include <fstream>
#include <ctime>
#include <cstdlib>
#define DL 1000000
#define DA 26
#define DN 100
using namespace std;

char sir[DL];

int main()
{
	srand(time(NULL));
	for(int i=13; i<20; ++i) {
		char fis[20];
		sprintf(fis,"grader_test%d.in",i);
		ofstream g(fis);
		int lgm=rand()%DL+1;
		int n=rand()%DN+1,lgperioada=rand()%DN;
		for(int i=0; i<lgperioada; ++i) sir[i]=rand()%DA+'a';
		for(int i=lgperioada; i<lgm; ++i) sir[i]=sir[i%lgperioada];
		g<<sir<<'\n'<<n<<'\n';
	
		for(int i=1; i<=n; ++i) {
			int a=rand()%lgm;
			int b=rand()%(lgm-a)+a;
			if(b==lgm || b<a || b-a>DN) {
				--i;
				continue;
			}
			for(int i=a; i<=b; ++i) g<<sir[i];
			g<<'\n';
		}
		g.close();
	}
	return 0;
}


