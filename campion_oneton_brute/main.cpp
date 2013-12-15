#include <iostream>
#include <fstream>
using namespace std;

int n=4,v[400000];

bool check() {
    for(int i=1; i<=2*n; ++i) if(v[i]!=i) return 1;
    return 0;
}

void tr() {
    int cv[400000];
    for(int i=1; i<=2*n; ++i) cv[i]=v[i];
    for(int i=1; i<=n; ++i) {
        //cout<<2*i-1<<' '<<i<<'\n';
        v[2*i-1]=cv[i];
    }
    //cout<<endl;
    for(int i=1; i<=n; ++i) {
        //cout<<2*i<<' '<<2*n-i+1<<'\n';
        v[2*i]=cv[2*n-i+1];
    }
}

int main()
{
    ofstream g("brute.out");
    for(n=1; n<=10000; ++n) {
        int r=1;
        for(int i=1; i<=2*n; ++i) v[i]=i;
       //for(int i=1; i<=2*n; ++i) cout<<v[i]<<' ';
       // cout<<'\n';
        for(tr();check();++r,tr()) {
            //for(int i=1; i<=2*n; ++i) cout<<v[i]<<' ';
            //cout<<'\n';
        }
        g<<n<<":"<<r<<'\n';
        g.flush();
    }
    return 0;
}
