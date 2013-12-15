#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#define DN 50000
using namespace std;

char in[500],out[500];
int n,m,gr[DN+5];

int gaseste(int i) {
    if(gr[i]==i) return i;
    gr[i]=gaseste(gr[i]);
    return gr[i];
}

void reuniune(int i,int j) {
    gr[gaseste(i)]=gaseste(j);
}

int main()
{
    srand(time(NULL));
    for(int i=6; i<=7; ++i) {
        sprintf(in,"grader_test%d.in",i);
        sprintf(out,"grader_test%d.ok",i);
        ofstream f(in); ofstream g(out);
        n=m=DN;
        m*=2;
        f<<n<<' '<<m<<'\n';

        int nadd=rand()%n;
        if(i==6) {
            nadd=n-1;
            for(int i=n; i>1; --i) {f<<"1 "<<i<<' '<<i-1<<'\n';
            reuniune(i,i-1);}
            m-=nadd;
            nadd=0;
        }
        if(i==7) {
            nadd=n-1;
            for(int i=1; i<n; ++i) {f<<"1 "<<i<<' '<<i+1<<'\n';
            reuniune(i,i+1);}
            m-=nadd;
            nadd=0;
        }

        for(int i=1; i<=n; ++i) gr[i]=i;
        m-=nadd;
        for(int i=1; i<=nadd; ++i) {
            int a=1,b=1;
            for(;gaseste(a)==gaseste(b);a=rand()%n+1,b=rand()%n+1);
            f<<"1 "<<a<<' '<<b<<'\n';
            reuniune(a,b);
        }
        for(int i=1; i<=m; ++i) {
            int a=rand()%n+1,b=rand()%n+1;
            f<<"2 "<<a<<' '<<b<<'\n';
            if(gaseste(a)==gaseste(b)) g<<"DA\n";
            else g<<"NU\n";
        }
        f.close(); g.close();
    }
    return 0;
}
