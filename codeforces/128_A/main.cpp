#include <iostream>
using namespace std;

int x,t,a,b,da,db,ok;

int main()
{
    cin>>x>>t>>a>>b>>da>>db;
    if(x==0) {
        cout<<"YES\n";
        return 0;
    }
    for(int i=0; i<t; ++i) if(x==a-i*da) ok=1;
    for(int i=0; i<t; ++i) if(x==b-i*db) ok=1;
    for(int i=0; i<t; ++i) for(int j=0; j<t; ++j)
        if(x==a-i*da+b-j*db)ok=1;
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
