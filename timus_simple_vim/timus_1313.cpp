#include <iostream>
#define DN 105
using namespace std;

int n,m[DN][DN];

void af(int a, int b) {
	if(a<=0 || b<=0 || a>n || b>n) return;
	cout<<m[a][b]<<' ';
	m[a][b]=-1;
	af(a-1,b+1);
}

int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) cin>>m[i][j];
	for(int j=1; j<=n; ++j) for(int i=1; i<=n; ++i) if(-1!=m[i][j]) af(i,j);
	return 0;
}
