#include <iostream>
#include <string>
#define DN 50
using namespace std;

string rez;
int n,k,fibo[DN]={1,2};

int main()
{
    cin>>n>>k;
    for(int i=2; i<=n+2; ++i) fibo[i]=fibo[i-1]+fibo[i-2];
    if(k>fibo[n]) {
        cout<<"-1";
        return 0;
    }
    for(int i=1; i<=n; ++i)
        if(fibo[n-i]<k) {
            rez+='1';
            k-=fibo[n-i];
        }else rez+='0';
    cout<<rez;
    return 0;
}
