#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std;

double a,b;
int t,n;
string x,y,r;

int main() {
	freopen("adbin.in","r",stdin);
	freopen("adbin.out","w",stdout);
    cin>>x>>y;
    for(int i=0; i<x.size(); ++i) {
        x[i]-='0';
        y[i]-='0';
    }
    for(int i=0; i<x.size(); ++i) r+=(x[i]^y[i])+'0';
    cout<<r;
}
