#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#define DN 9999999999
#define DM 999999999
using namespace std;

#define FOUT "kingsort.out"
#define FOK  "kingsort.ok"

void error(char msg[], double p)
{
	fprintf(stderr, msg);
	printf("%lf", p);
	exit(0);
}

string s1,s2;
int main(void)
{
	ifstream f(FOUT); ifstream g(FOK);
    getline(f,s1); getline(g,s2);
    
    if(s1.compare(s2)==0) error("Mere binie",0.25);
    else error("Esti prost!",0);

    return 0;
}

