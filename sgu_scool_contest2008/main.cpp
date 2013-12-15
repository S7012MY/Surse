#include <iostream>
#include <algorithm>
#define DN
using namespace std;

int a[4],b[4];

int main()
{
    for(int i=1; i<=3; ++i) {
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+4);
        b[i]=a[2];
    }
    sort(b+1,b+4);
    cout<<b[2];
    return 0;
}
