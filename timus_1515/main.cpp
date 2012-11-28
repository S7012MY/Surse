#include <iostream>
#include <bitset>
using namespace std;

int n,d[105],wmax=1;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>d[i];
        if(d[i]>wmax) {
            cout<<wmax;
            return 0;
        }
        wmax+=d[i];
    }
    cout<<wmax;
    return 0;
}
