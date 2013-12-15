#include <iostream>
#include <fstream>
using namespace std;

int n,m;

int main()
{
    ifstream f("minerale.in");
    ofstream g("minerale.out");
    f>>n>>m;
    for(int i=1; i<=m; ++i) g<<i%3<<'\n';
    return 0;
}
