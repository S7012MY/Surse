#include <iostream>
#include <cmath>
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
per a,b,c,d;

double dist(per a,per b) {
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    double ab=dist(a,b),bc=dist(b,c),cd=dist(c,d),da=dist(d,a);
    if(ab==cd && bc==da) {
      if(ab==bc) cout<<8;
      else cout<<4;
    } else if((ab==bc && cd==da) || (ab==da && bc==cd)) cout<<2;
    else cout<<0;
    return 0;
}
