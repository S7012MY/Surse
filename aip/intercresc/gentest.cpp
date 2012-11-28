#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define DN 200005
#define LIM 100000
using namespace std;

int n,m,a[DN],b[DN],rez[DN];
int NM=(1<<30);

int main() {
	srand(time(NULL));
	for(int i=1; i<=10; ++i) {
		char in[55],ou[55];
		sprintf(in,"grader_test%d.in",i);
		sprintf(ou,"grader_test%d.ok",i);
		ofstream f(in); ofstream g(ou);
		
		n=rand()%LIM+1; m=rand()%LIM+1;
		if(i<4) {
			n=rand()%10+1; m=rand()%10+1;
			NM=100;
		}else NM=(1<<30);
		f<<n<<' '<<m<<'\n';
		for(int i=1; i<=n; ++i) {
			a[i]=rand()%NM;
			rez[i]=a[i];
		}
		for(int i=1; i<=m; ++i) {
			b[i]=rand()%NM;
			rez[i+n]=b[i];
		}
		sort(a+1,a+n+1); sort(b+1,b+m+1);
		for(int i=1; i<=n; ++i) f<<a[i]<<' ';
		f<<'\n';
		for(int j=1; j<=m; ++j) f<<b[j]<<' ';
		sort(rez+1,rez+n+m+1);
		for(int i=1; i<=n+m; ++i) g<<rez[i]<<' ';
		
		
	}
	return 0;
}
