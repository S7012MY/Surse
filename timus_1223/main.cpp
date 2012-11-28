#include <iostream>
#include <cmath>
using namespace std;

int a,b,nr[20][1005];

int memo(int a,int b) {
    //cout<<a<<' '<<b<<":\n";
	if(nr[a][b]) return nr[a][b];
	if(a==1) {
		nr[a][b]=b;
		return b;
	}
	if(b==1) {
		nr[a][b]=1;
		return 1;
	}
	if(b==0) return 0;
	nr[a][b]=99999;
	//for(int i=1; i<=b; ++i) cout<<a-1<<' '<<i<<' '<<a<<' '<<b-i<<'\n';
	for(int i=1; i<=b; ++i) nr[a][b]=min(nr[a][b],max(memo(a-1,i-1),memo(a,b-i)));
	++nr[a][b];
	return nr[a][b];
}

int main() {
	for(cin>>a>>b;;cin>>a>>b) {
	    if(a>=15) a=15;
		if(a==0) break;
		if(a==1) cout<<b<<'\n';
		else cout<<memo(a,b)<<'\n';
	}
	return 0;
}
