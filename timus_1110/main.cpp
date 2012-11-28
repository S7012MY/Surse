#include <iostream>
using namespace std;

int n,m,y;

int putere(int x,int y) {
	int rezultat=1,baza=x,exponent=y;
	while(exponent>0) {
		while(!(exponent%2)) {
			exponent>>=1;
			baza=(baza*baza)%m;
		}
		exponent--;
		rezultat=(rezultat*baza)%m;
	}
	return rezultat;
}

int main()
{
    cin>>n>>m>>y;
    int ok=0;
    for(int i=0; i<m; ++i) {
        int r=putere(i,n);
        if(r==y) {
            ok=1;
            cout<<i<<' ';
        }
    }
    if(0==ok) cout<<"-1";
    return 0;
}
