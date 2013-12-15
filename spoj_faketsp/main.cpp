#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cctype>
#define x first
#define y second
using namespace std;

typedef pair<double, double> per;

double dist(per a, per b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

string inp,nr[2];
int cc;

int main()
{
    per p,c;
    getline(cin,inp);
    for(int i=0; i<inp.size(); ++i) if(isalpha(inp[i])) {
        for(;isalpha(inp[i]);++i) nr[cc]+=inp[i];
        --i;
        ++cc;
    }
    stringstream s;
    s<<nr[0];//<<' '<<nr[1];
    s>>p.x;//>>p.y;
    cout<<nr[0]<<' '<<nr[1]<<'\n';
    cout.flush();
	for(;!cin.eof();) {
	}
	return 0;
}
