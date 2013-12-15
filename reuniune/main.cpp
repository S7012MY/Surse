#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct d{
    int x1,y1,x2,y2;
}d1,d2,d3;

void afis(d a) {
    cout<<a.x1<<' '<<a.y1<<' '<<a.x2<<' '<<a.y2<<'\n';
}

int arie(d a) {
    return abs(a.x2-a.x1)*abs(a.y2-a.y1);
}

d is(d a, d b) {
    d rez;
    //afis(a); afis(b);
    rez.x1=rez.x2=rez.y1=rez.y2=0;
    if(a.x1<=b.x1 && b.x1<=a.x2) rez.x1=b.x1;
    if(a.y1<=b.y1 && b.y1<=a.y2) rez.y1=b.y1;
    if(b.x1<=a.x1 && a.x1<=b.x2) rez.x1=a.x1;
    if(b.y1<=a.y1 && a.y1<=b.y2) rez.y1=a.y1;

    if(a.x1<=b.x2 && b.x2<=a.x2) rez.x2=b.x2;
    if(a.y1<=b.y2 && b.y2<=a.y2) rez.y2=b.y2;
    if(b.x1<=a.x2 && a.x2<=b.x2) rez.x2=a.x2;
    if(b.y1<=a.y2 && a.y2<=b.y2) rez.y2=a.y2;
    return rez;
}

int fa(d d1,d d2,d d3) {
    int tot=arie(d1)+arie(d2)+arie(d3);
    d i12=is(d1,d2),i23=is(d2,d3),i13=is(d1,d3);
    tot-=(arie(i12)+arie(i23)+arie(i13));
    i12=is(i12,i23); i12=is(i12,i13);
    tot+=arie(i12);
    return tot;
}

int main()
{
    ifstream f("reuniune.in");
    ofstream g("reuniune.out");
    f>>d1.x1>>d1.y1>>d1.x2>>d1.y2;
    f>>d2.x1>>d2.y1>>d2.x2>>d2.y2;
    f>>d3.x1>>d3.y1>>d3.x2>>d3.y2;
    g<<fa(d1,d2,d3);
    return 0;
}
