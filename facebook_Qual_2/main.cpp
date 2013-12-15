#include <iostream>
#define DM 10000005
using namespace std;

//    Pi = ((A*Pi-1 + B) mod M) + 1 (for all i = 2..N)
//    Wi = ((C*Wi-1 + D) mod K) + 1 (for all i = 2..N)

int t,n,p1,w1,m,k,a,b,c,d,p2,w2;

int main()
{
    cin>>n>>p1>>w1>>m>>k>>a>>b>>c>>d;
    for(int i=2; i<=n; ++i) {
        p2=((a*p1+b)%m)+1;
        w2=((c*w1+d)%k)+1;
        cout<<'\n'<<p2<<' '<<w2;
        p1=p2;
        w1=w2;
    }
    return 0;
}
