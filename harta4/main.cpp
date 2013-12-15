#include <iostream>
#include <fstream>
#define DN 35
#define MULT (1<<30)
using namespace std;

int n,m,mt[DN][DN],bst[DN][DN][DN][DN];

int memo(int i, int j, int a, int b) {
    if(bst[i][j][a][b]) return bst[i][j][a][b];
    int ok=1;
    for(int x=i; x<=a; ++x) for(int y=j; y<=b; ++y) if(mt[x][y]!=mt[i][j]) ok=0;
    if(ok) {
        bst[i][j][a][b]=1;
        return 1;
    }
    int r=MULT;
    //linie
    for(int k=i; k<a; ++k) r=min(r,memo(i,j,k,b)+memo(k+1,j,a,b));
    //coloana
    for(int k=j; k<b; ++k) r=min(r,memo(i,j,a,k)+memo(i,k+1,a,b));
    bst[i][j][a][b]=r+2;
    return r+2;
}

int main()
{
    ifstream f("harta4.in");
    ofstream g("harta4.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) f>>mt[i][j];
    g<<memo(1,1,n,m);
   // cout<<memo(1,1,2,3);
    return 0;
}
