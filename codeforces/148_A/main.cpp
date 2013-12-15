#include <iostream>
using namespace std;

int y,k,n;

int main()
{
    cin>>y>>k>>n;
    int ok=0;
    for(int i=0; i<=n; i+=k) if(i>y){
        ok=1;
        cout<<i-y<<' ';
    }
    if(!ok) cout<<-1;
    return 0;
}
