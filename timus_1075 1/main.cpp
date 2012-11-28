#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct p{
    double x,y,z;
} A,B,C;

double r;

double dist(p a, p b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int main()
{
    cin>>A.x>>A.y>>A.z;
    cin>>B.x>>B.y>>B.z;
    cin>>C.x>>C.y>>C.z>>r;
    double AC=dist(A,C),BC=dist(B,C),AB=dist(A,B);
    double Aa=sqrt(AC*AC-r*r),Bb=sqrt(BC*BC-r*r);
    double ACa=acos((Aa*Aa-r*r-AC*AC)/(-2*AC*r));
    double BCb=acos((Bb*Bb-r*r-BC*BC)/(-2*BC*r));
    double ACB=acos((AB*AB-AC*AC-BC*BC)/(-2*AC*BC));
    double aCb=ACB-ACa-BCb;
    double ab=aCb*r;
    //cout<<Aa<<' '<<ab<<' '<<Bb<<'\n';
    if(ab>0)cout<<fixed<<setprecision(2)<<Aa+ab+Bb;
    else cout<<AB;
    return 0;
}
