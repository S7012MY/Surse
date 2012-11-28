#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 2000005
using namespace std;

int n,m,l,s,x,y,z,v,t[DN];

//    di = ( X * di-1 + Y * ( i - 1 ) ) % ( L - 1 ) + 1
//    ti = ( Z * di-1 + V * ( i - 1 ) ) % 2
//    rezultatul in T[ (M-1)%N +1 ] + ( (M+N-1)/N - 1) * 2 * L , T sortat crescator


int main()
{
	ifstream f("toys.in");
	ofstream g("toys.out");
	f>>n>>l>>m>>s>>x>>y>>z>>v;
	t[1]=l+s;
	int dp=s,tp=1,tc,dc;//dp=dist prec tp t precedent(t = 1 daca transp jucarie)
	for(int i=2; i<=n; ++i) {
		dc=(1LL*x*dp+1LL*y*(i-1))%(l-1)+1;
       		tc=(1LL*z*dp+1LL*v*(i-1))%2;
		if(tc) t[i]=l+dc;
		else t[i]=l-dc;
		dp=dc; tp=tc;
	}
	int poz=(m-1)%n+1;
	nth_element(t+1,t+poz,t+n+1);
	g<<1LL*t[(m-1)%n+1]+1LL*((m+n-1)/n-1)*2*l+l;
	return 0;
}

