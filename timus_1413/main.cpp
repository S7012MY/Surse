#include <iostream>
#include <iomanip>
#include <cmath>
#define cons sqrt(2)/2
using namespace std;

int main()
{
    double x=0,y=0;
    char c;
    for(;!cin.eof();) {
        cin>>c;
        c-='0';
        if(c==0) break;
        if(1==c)x-=cons,y-=cons;
        else if(2==c) --y;
        else if(3==c) x+=cons,y-=cons;
        else if(4==c) --x;
        else if(6==c) ++x;
        else if(7==c) x-=cons,y+=cons;
        else if(8==c) ++y;
        else if(9==c) x+=cons,y+=cons;
        else;
    }
    cout<<fixed<<setprecision(10)<<x<<' '<<y;
    return 0;
}
