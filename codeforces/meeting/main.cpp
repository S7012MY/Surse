#include <fstream>
#include <iomanip>
using namespace std;

double x,y,z,lg,arie;

int main()
{
    ifstream cin("meeting.in");
    ofstream cout("meeting.out");
    cin>>x>>y>>z;
    x*=60; y*=60;
    lg=(y-x);
    arie=(lg-z); arie*=arie;
    lg*=lg;
    cout<<fixed<<setprecision(7)<<1.0-(arie/lg);
    return 0;
}
