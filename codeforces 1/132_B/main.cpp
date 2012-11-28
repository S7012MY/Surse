#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define DN 5005
using namespace std;

int n,m,k,x[DN],y[DN],z[DN];
double a,b;

double retr2(double r1, double q1, double q2) {
    return sqrt((b*q1*r1*r1)/(a*q2+b*q1));
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>x[i];//r1
    cin>>m;
    for(int i=1; i<=m; ++i) cin>>y[i];//q1
    cin>>k;
    for(int i=1; i<=k; ++i) cin>>z[i];//q2
    cin>>a>>b;


    sort(x+1,x+n+1);
    sort(y+1,y+m+1);
    sort(z+1,z+k+1);

    double r2=retr2(x[n],y[m],z[1]);
    cout<<fixed<<setprecision(10)<<r2;
    return 0;
}
