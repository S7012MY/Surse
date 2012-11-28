#include <iostream>
#include <fstream>
using namespace std;

int n;

int count(int n) {
	int num=0;
	do {
		++num;
	}while(n&=(n-1));
	return num;
}

int main()
{
    ifstream f("brad.in");
    ofstream g("brad.out");
    f>>n;
    int nrb=count(n)-1;
    int rc=(1<<nrb);
    g<<rc;
    return 0;
}
