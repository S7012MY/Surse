/*
ID: l3asket1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
using namespace std;

int n,nrz[]

int main()
{
	string a,b;
	ifstream f("gift1.in");
	ofstream g("gift1.out");
	f>>np;
	for(int i=0; i<np; ++i) {
	    f>>pc;
	    inp.push_back(pc);
	    pers[pc]=0;
	}
	for(int i=0; i<np; ++i) {
	    f>>pc>>sum>>ng;
	    pers[pc]-=sum;
	    if(ng) pers[pc]+=sum%ng;
	    if(0==ng) continue;
	    int catDa=sum/ng;
	    for(int j=0; j<ng; ++j) {
	        f>>pc;
	        pers[pc]+=catDa;
	    }
	}
	for(int i=0; i<inp.size(); ++i) g<<inp[i]<<' '<<pers[inp[i]]<<'\n';
	return 0;
}
