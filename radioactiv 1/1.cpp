#include <iostream>
#include <fstream>
#define DN 705
#define N 100
using namespace std;

int n,k,v[DN][DN],sp[DN][DN];

int main()
{
	ifstream f("radioactiv.in");
	ofstream g("radioactiv.out");
	f>>n>>k;
	for(int i=N; i<n+k+N; ++i) for(int j=N; j<n+k+N;++j) {
		if(i<n+N && j<n+N) f>>v[i][j];
		sp[i][j]=sp[i][j-1]+sp[i-1][j]+v[i][j]-sp[i-1][j-1];
	}
	int vl=999999999,c=0;
	for(int i=N; i<n+N; ++i) for(int j=N;j<n+N; ++j) {
		int sum=v[i][j];
		for(int d=1; d<k; ++d) sum+=sp[i+d][j+d]-sp[i+d][j-d-1]-sp[i-d-1][j+d]+sp[i-d-1][j-d-1];
		if(sum<vl) vl=sum,c=1;
		else if(sum==vl) ++c;
	}
	g<<c;
	return 0;
}
	