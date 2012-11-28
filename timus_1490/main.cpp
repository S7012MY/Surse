#include <iostream>
using namespace std;

long long r,s;

int main()
{
    long long sx,sy;
    cin>>r;
    sx=0;sy=r-1;
    for(;sx<r;++sx) {
        for(;sx*sx+sy*sy>=r*r;--sy);
      //  cout<<sx<<' '<<sy<<'\n';
        s+=sy+1;
    }
    cout<<4LL*s;
    return 0;
}
