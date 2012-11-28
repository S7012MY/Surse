#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;

bitset<1000001> bec[2];
vector<int> poz[200],v;

int n;

int main()
{
    ifstream f("brad.in");
    ifstream g("brad.out");
    f>>n;
    bec[0][0]=1;
    int rc;
    for(int i=1; i<=n; ++i) {
        rc=0;
        bec[i&1]&=0;
        for(int j=1; j<=1000000; ++j) {
            if(bec[(i&1)^1][j-1] && !bec[(i&1)^1][j+1]) bec[i&1][j]=1;
            if(!bec[(i&1)^1][j-1] && bec[(i&1)^1][j+1]) bec[i&1][j]=1;
        }
        for(int j=1; j<=1000000; ++j) if(bec[i&1][j]) ++rc;
        //poz[rc].push_back(i);
    }
    int rb;
    g>>rb;
    if(rc!=rb) {
        cout<<"gresit";
        cout.flush();
        while(1);
    }
    cout<<"corect\n";
    return 0;
}
