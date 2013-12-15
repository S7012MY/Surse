#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define DN 1000
using namespace std;

int n,k,d[DN],s[DN];

int main()
{
    srand(time(NULL));
    for(int t=3; t<=3; ++t) {
        char in[55],ou[55];
        sprintf(in,"grader_test%d.in",t);
        sprintf(ou,"grader_test%d.ok",t);
        ofstream f(in); ofstream g(ou);

        n=rand()%DN+1; k=rand()%DN+1;
        f<<n<<' '<<k<<'\n';
        for(int i=1; i<=n; ++i) {
            d[i]=rand()%DN+1;
            f<<d[i]<<' ';
        }
        f<<'\n';
        for(int i=1; i<=n; ++i) {
            s[i]=rand()%DN+1;
            f<<s[i]<<' ';
        }
        int cc=0,tt=0,mc=0;
        for(int i=1; i<=n; ++i) {
            cc+=s[i];
            mc=max(mc,s[i]);
            for(;cc<d[i];cc+=mc,tt+=k);
            tt+=d[i];
            cc-=d[i];
        }
        g<<tt;
    }
    return 0;
}
