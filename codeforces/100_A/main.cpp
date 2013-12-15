#include <iostream>
using namespace std;

int n,R,r,rmic;
double A,pi=3.14159265358,amic,a;

int main()
{
    cin>>n>>R>>r;
    if(n==1) {
        if(R>=r) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    if(n==2) {
        if(R>=r+r) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    if(2*pi*(R-r)>2*n*r) cout<<"YES";
    else cout<<"NO";
    return 0;
}
