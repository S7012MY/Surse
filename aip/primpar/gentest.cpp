#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

char in[55],ou[55];

int isp(int x) {
	for(int i=2; i*i<=x; ++i) if(x%i==0) return 0;
	return 1;
}

int sumcif(int x) {
	int r=0;
	for(;x;r+=x%10,x/=10);
	return r;
}

int main() {
	srand(time(NULL));
	for(int i=1; i<=20; ++i) {
		int x=rand()%100000+1;
		if(x<3) x=3;
		if(i<6) x=rand()%500;
		
		sprintf(in,"grader_test%d.in",i);
		sprintf(ou,"grader_test%d.ok",i);
		ofstream f(in); ofstream g(ou);
		f<<x;
		
		for(int i=2; i<x; ++i) if(isp(i) && sumcif(i)%2==0) g<<i;
	}
}
