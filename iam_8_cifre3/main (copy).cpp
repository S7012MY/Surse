#include <iostream>
#include <fstream>
#include <set>
#define LL long long
using namespace std;

int n,f[22]={1};
set<LL> s;

void back(int sz) {
    if(sz==n+1) {
        LL r=1;
        for(int i=1; i<=n; ++i) {
            r*=f[i];
            //cout<<f[i];
        }
        //cout<<'\n';
        s.insert(r);
        return;
    }

    for(int i=f[sz-1]; i<10; ++i) {
        f[sz]=i;
        back(sz+1);
    }
}

int main()
{
    ifstream f("cifre3.in");
    ofstream g("cifre3.out");
    int a,b;
    for(int a=0; a<20; ++a) {
        for(int b=a; b<20; ++b) {
            n=b;
            if(n>1) s.insert(0);
            back(1);
            g<<"m["<<a<<"]["<<b<<"]="<<s.size()<<";";
            cout<<a<<' '<<b<<'\n';
        }
        s.clear();
    }
    return 0;
}
