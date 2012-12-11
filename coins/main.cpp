#include <iostream>
#include <fstream>
#define DN 22
using namespace std;

int bst[1<<DN],n,rez;

int memo(int state) {
    int r=(1<<30)
    if(bst[state]!=-1) return bst[state];
    int lb=-1
    for(int i=0; i<22; ++i)
        if(state&(1<<i)) {

        }else lb=i;
}


int main()
{
    ifstream f("coins.in");
    ofstream g("coins.out");
    for(int i=1; i<(1<<DN); ++i) bst[i]=-1;
    for(f>>n;n;--n) {
        int si=0,x;
        for(int i=0; i<22; ++i) {
            f>>x;
            si<<=1;
            if(x)si|=1;
        }
        rez+=memo(si);
    }
    g<<rez;
    return 0;
}
