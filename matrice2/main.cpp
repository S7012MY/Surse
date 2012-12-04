#include <iostream>
#include <fstream>
#define DN 305
using namespace std;

int n,q,m[DN][DN],pre[DN*DN],l;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int main()
{
    ifstream f("matrice2.in");
    ofstream g("matrice2.out");
    f>>n>>q; l=n*n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) f>>m[i][j];

    for(int s=(1<<20);s;s>>=1) {
        for(int i=1; i<=lm; ++i) pre[i]=i;
        for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(m[i][j])
    }
    return 0;
}
