#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#define C 80000
using namespace std;

int v[80005];

int main()
{
    ofstream g("sccm.in");
    g<<"80000 80000\n";
    for(int i=1; i<=C; ++i) v[i]=i;
    srand(time(NULL));
    random_shuffle(v+1,v+C+1);
    for(int i=1; i<=C; ++i) g<<v[i]<<' ';
    g<<'\n';
    random_shuffle(v+1,v+C+1);
    for(int i=1; i<=C; ++i) g<<v[i]<<' ';
    return 0;
}
