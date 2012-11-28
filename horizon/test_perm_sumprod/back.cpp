#include <fstream>
#include <iostream>
#include <algorithm>
#define DN 15
using namespace std;

int n,v[DN],bst=1<<30,sb[DN];

int main() {
	ifstream f("in.in");
	f>>n;
	for(int i=1; i<=n; ++i) f>>v[i];
	do {
		int rez=0;
		for(int i=2; i<=n; ++i) rez+=(v[i]*v[i-1]);
		if(rez<bst) {
			bst=rez;
			for(int i=1; i<=n; ++i) sb[i]=v[i];	
		}
	}while(next_permutation(v+1,v+n+1));
	ifstream g("in.out");
	int rb;
	g>>rb;
	if(rb!=bst) {
		//cout<<"gresit\n back/bun:"<<bst<<' '<<rb;
		for(int i=1; i<=n; ++i) cout<<sb[i]<<' ';
		cout<<'\n';
		cout.flush();
		while(1);
	}else cout<<"OK!\n";
}
