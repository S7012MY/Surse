#include <iostream>
#include <algorithm>
#define MAXB 20
#define DN 100005
#define x first
#define y second
using namespace std;

int n,a[DN],nxt[MAXB][DN];//urmatorul bit de dupa numar

int main() {
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int i=0; i<MAXB; ++i) {
		nxt[i][n+1]=n;
		for(int j=n; j; --j) {
			if(a[j]&(1<<i)) nxt[i][j]=i;
			else nxt[i][j]=nxt[i][j+1];
		}
	}
	
}