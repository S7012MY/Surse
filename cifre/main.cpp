#include <fstream>
#include <iomanip>
using namespace std;

int nrc(int nr,int c) {
    int cnt=0;
    for(;nr!=0;nr/=10) if(nr%10==c) ++cnt;
    return cnt;
}

int main()
{
    int a,b,k,c,nrp,nrb=0;
    ifstream f("cifre.in");
    ofstream g("cifre.out");
    f>>a>>b>>c>>k;
    nrp=b-a+1;
    if(nrp<=1000000) {
        for(int i=a; i<=b; ++i) if(nrc(i,c)>=k) ++nrb;
        g<<fixed<<setprecision(4)<<(1.0*nrb)/(1.0*nrp);
    }
    return 0;
}
