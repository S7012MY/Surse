/*#include <iostream>
using namespace std;

bool check(int nr, int b) {
	for(;nr;nr/=10) if(nr%10>=b) return 0;
	return 1;
}

int trans(int nr, int b) {
	int r=0,put=1;
	for(;nr;nr/=10) {
		r+=(nr%10)*put;
		put*=b;
	}
	return r;
}

int main()
{
	for(int b=3; b<=10; ++b) {
		cout<<b<<":\n";
		for(int nr=1; nr<=999; ++nr) if(check(nr,b)) {
			if(trans(nr,b)%(b-1)==0) cout<<nr<<' ';
		}
		cout<<endl;
	}
	return 0;
}*/
