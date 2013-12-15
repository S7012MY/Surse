#include <fstream>
#include <string>
using namespace std;

int p,r1;
int cst[]={0,2,5,5,4,5,6,3,7,6};
string ns,r2;

int main()
{
    ifstream f("7segmente.in");
	ofstream g("7segmente.out");
	f>>ns>>p;
	int nc=ns.size();
	for(int i=0;i<nc;r1+=cst[ns[i]-'0'],++i);
	int ctot=0,ok=0,okpas=0;
	for(int c=1; c<=nc; ++c) {
	    okpas=0;
	    int cc=ns[c-1]-'0';
	    if(ok) cc=9;
	    for(; cc; --cc) if(ctot+cst[cc]+(nc-c)*2<=p) {
	        if(cc<ns[c-1]-'0') ok=1;
	        okpas=1;
	        ctot+=cst[cc];
	        r2+=cc+'0';
	        break;
	    }
	    if(!okpas) ok=1;
	}
	g<<r1<<' '<<r2;
    return 0;
}
