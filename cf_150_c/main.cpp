#include <iostream>
#define DN 100005
using namespace std;

int n,v[DN],r=1;

int main()
{
    cin>>n;
    for(int z=1; z<31; ++z) {
        int nr[2]={0,0};
        for(int i=1; i<=n; ++i) {
            if(v[i]&1) nr[1]=1;
            else nr[0]=1;
            v[i]>>=1;
        }
        if(nr[0]+nr[1]==2) r<<=1;
    }
    cout<<r;
    return 0;
}
