#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int m,d1,d2;
    cin>>m>>d1>>d2;
    double oz=(double)(1/d1*m),fr=(double)m*d1/d2;
   // cout<<fixed<<setprecision(8)<<oz<<' '<<fr;
    for(int i=0; i<=d2; ++i) if((double)i*floor(fr)+(double)(d2-i)*(ceil(fr))==d1*m) {
        for(int j=1; j<=i; ++j) cout<<floor(fr)<<' ';
        for(int j=i+1; j<=d2; ++j) cout<<ceil(fr)<<' ';
        //cout<<endl<<i<<' ';
        return 0;
    }
    return 0;
}
