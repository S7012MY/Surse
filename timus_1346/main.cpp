#include <iostream>
using namespace std;

int a,b,rez=1,ap,ac,tp;//1 crescator,2 descrescator 0 egal

int main()
{
    cin>>a>>b;
    cin>>ap;
    for(int i=a+1; i<=b; ++i) {
        cin>>ac;
        if(tp==1 && ap>ac) {
            ++rez;
            tp=0;
            ap=ac;
            continue;
        }
        if(tp==2 && ap<ac) {
            ++rez;
            tp=0;
            ap=ac;
            continue;
        }
        if(tp==0 && ap<ac) {
            tp=1;
            ap=ac;
            continue;
        }
        if(tp==0 && ap>ac) {
            tp=2;
            ap=ac;
            continue;
        }
        ap=ac;
    }
    cout<<rez;
    return 0;
}
