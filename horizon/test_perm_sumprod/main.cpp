/* Sa se gaseasca o permutare a sirului astfel incat suma produselor el adiacente sa fie maxima
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 15
using namespace std;

int n,v[DN],aux[DN];

int main()
{
    ifstream f("in.in");
    ofstream g("in.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>v[i];
        aux[i]=v[i];
    }
    sort(aux+1,aux+n+1);
    int ls=1,ld=n,st=0,dr=n+1;
    for(int i=1; i<=n; ++i)
        if(i%4==1) v[--dr]=aux[ld--];
        else if(i%4==2) v[++st]=aux[ld--];
        else if(i%4==3) v[--dr]=aux[ls++];
        else v[++st]=aux[ls++];
    int rez=0;
    for(int i=2; i<=n; ++i) rez+=(v[i]*v[i-1]);
    g<<rez;
    for(int i=1; i<=n; ++i) cout<<v[i]<<' ';
    return 0;
}
