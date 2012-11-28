#include <iostream>
#include <fstream>
#define DN 505
using namespace std;

int n,a[DN][DN],b[DN][DN],l[DN],c[DN],rez;

int main()
{
    ifstream f("panou.in");
    ofstream g("panou.out");
    f>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) f>>a[i][j];
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) f>>b[i][j];
    for(int i=n; i>0; --i) for(int j=n; j>0; --j)
        if((a[i][j]+l[i]+c[j])%2!=b[i][j]) {
            ++rez;
            ++l[i];
            ++c[j];
        }
    g<<rez;
    return 0;
}
