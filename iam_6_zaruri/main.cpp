#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

long long a[25]={0,21},cate=6;
int n;

int main()
{
    ifstream f("zaruri.in");
    ofstream g("zaruri.out");
    f>>n;
    for(int i=2; i<=n; i++){
        for(int j=1; j<=6; j++) a[i]+=max(j*cate,a[i-1]);
        cate*=6;
    }
    g<<fixed<<setprecision(10)<<(double)a[n]/cate;
    return 0;
}
