#include <iostream>

using namespace std;

int n,m,rez;

int main()
{
    cin>>n>>m;
    for(int a=-1000; a<=1000; ++a)
        for(int b=-1000; b<=1000; ++b)
            if(a*a+b==n && a+b*b==m) ++rez;
    cout<<rez;
    return 0;
}
