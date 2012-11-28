#include <fstream>
#define DN 1000005
#define M 2011
using namespace std;

int n,k,p[DN],m[DN],aux;

int main()
{
	ifstream f("minusk.in");
	ofstream g("minusk.out");
	f>>n>>k;
	p[0]=p[1]=m[1]=1;
	for(int i=2; i<=n; ++i) {
		p[i]=m[i]=(p[i-1]+m[i-1])%M;
		if(i>=k) aux=p[i-k];
		else aux=0;
		m[i]-=aux;
		if(0>m[i])  m[i]+=M;
	}
	g<<(p[n]+m[n])%M;
	return 0;
}
