#include <iostream>
#include <cmath>
using namespace std;

//long long n;
int a[100]={0,1,1,2},l;//,l,fol[100],r;
/*
void bk(int k) {
    if(k>l) {
        ++r;
        return;
    }
    for(int i=2; i<=l; ++i) if(!fol[i] && abs(a[k-1]-i)<=2) {
        fol[i]=1;
        a[k]=i;
        bk(k+1);
        fol[i]=0;
    }
}
*/
int main()
{
    cin>>l;
    for(int i=4; i<=l; ++i) a[i]=a[i-1]+a[i-3]+1;
    /*for(l=1; l<=40; ++l) {
        a[1]=fol[1]=1;
        bk(2);
        cout<<l<<": "<<r<<'\n';
        //cout<<r;
        r=0;
    }*/
    cout<<a[l];
    return 0;
}
