#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

bitset<1000001> bec[2];

int main()
{
    bec[0][0]=1;
    for(int i=1; i<(1<<15); ++i) {
        int rc=0;
        bec[i&1]&=0;
        for(int j=1; j<=1000000; ++j) {
            if(bec[(i&1)^1][j-1] && !bec[(i&1)^1][j+1]) bec[i&1][j]=1;
            if(!bec[(i&1)^1][j-1] && bec[(i&1)^1][j+1]) bec[i&1][j]=1;
        }
        for(int j=1; j<=1000000; ++j) if(bec[i&1][j]) ++rc;
        cout<<i<<" : "<<rc<<'\n';
    }
    return 0;
}
