#include <iostream>
#include <cmath>
using namespace std;

double dist(double x1,double y1,double x2,double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    int t;
    for(cin>>t;t--;) {
        int r,x1,y1,x2,y2;
        cin>>r>>x1>>y1>>x2>>y2;
        if(r==dist(x1,y1,0,0) && dist(x2,y2,0,0)==r) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
