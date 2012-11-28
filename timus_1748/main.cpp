#include <iostream>
#include <fstream>
using namespace std;

int nrd;

int nd(int nr) {
    int cnt=0;
    for(int i=1; i<=nr; ++i) if(0==nr%i)++cnt;
    return cnt;
}

int main()
{
    ofstream g("brute.out");
    for(int i=1; i<=10000000; ++i) {
        cout<<i<<'\n';
        if(nd(i)>nrd) {
            nrd=nd(i);
            g<<i<<' '<<nrd<<'\n';
            g.flush();
        }
    }
    return 0;
}
