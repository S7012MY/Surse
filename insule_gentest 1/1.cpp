#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	for(int i=0; i<100; ++i) {
		char ifile[55],ofile[55];
		sprintf(ifile,"%d-insule.in",i);
		sprintf(ofile,"%d-insule.ok",i);
		ofstream g(ifile);
		ofstream h(ofile);
		h<<"1";
		g<<"500 500\n";
		int rs=rand()%5+2;
		for(int i=0; i<500; ++i) {
			for(int j=0; j<500; ++j)
				if(rand()%rs) g<<1;
				else g<<0;
			g<<'\n';
		}
		g.close();
		h.close();
	}
	return 0;
}
