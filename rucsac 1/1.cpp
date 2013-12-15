#include <fstream>
#define DN 5005
#define DG 10005
using namespace std;

int n,g,dp[2][DG],w[DN],p[DN];

int main()
{
	ifstream f("rucsac.in");
	ofstream out("rucsac.out");
	f>>n>>g;
	for(int i=1; i<=n; ++i) f>>w[i]>>p[i];
	for(int i=1; i<=n; ++i) for(int j=0; j<=g; ++j)
		if(j<w[i]) dp[i&1][j]=dp[(i&1)^1][j];
		else dp[i&1][j]=max(dp[(i&1)^1][j],dp[(i&1)^1][j-w[i]]+p[i]);
	out<<dp[n&1][g];
	return 0;
}
