#include <iostream>
#include <fstream>
using namespace std;

int n;

int count(int n) {
	int num=0;
	do {
		++num;
	}while(n&=(n-1));
}

int main()
{
    ifstream f("brad.in");
    ifstream g("brad.out");
    f>>n;
    int nrb=count(n);
    int rc=1<<nrb,rb;
    f>>rb;
    if(rc!=rb) {
        cout<<"gresit";
        cout.flush();
        while(1);
    }
    cout<<"corect\n";
    return 0;
}
