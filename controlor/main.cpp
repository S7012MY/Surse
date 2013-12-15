#include <iostream>
#include <fstream>
#define DN 1005
using namespace std;

int n,m[DN][DN],rez[DN][DN],sp[DN][DN];

int main()
{
    ifstream f("controlor.in");
    ofstream g("controlor.out");
    f>>n;
    for(int i=1; i<n; ++i) for(int j=i+1; j<=n; ++j) f>>m[i][j];
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
        sp[i][j]=m[i][j]+sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
    for(int i=1; i<n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            rez[i][j]=sp[j-1][n]-sp[i-1][n]-sp[j-1][j-1]+sp[i-1][j-1];
            g<<rez[i][j]<<' ';
        }
        g<<'\n';

    }
    return 0;
}
