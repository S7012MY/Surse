/*
    Se da o stiva.
    Fiecare element are asociat un profit si un cost de a fi scos din stiva si nefolosit.
    Sa se determine profitul maxim de a alege k elemente

*/
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#define DN 1000000
#define DK 2000
using namespace std;

int n,k,p[DN+1],c[DN+1],bst[DN+1],ssol,pt,rez;
multiset<int> sol,rst;

int main()
{
    srand(time(NULL));
    for(int i=6; i<21; ++i) {
        char fin[55],out[55];
        sprintf(fin,"teste/grader_test%d.in",i);
        sprintf(out,"teste/grader_test%d.ok",i);
        ofstream in(fin);
        ofstream g(out);
        n=rand()%DN+1;k=rand()%n+1;
        in<<n<<' '<<k<<'\n';
        for(int i=1; i<=n; ++i) {
            p[i]=rand()%DK+1; c[i]=rand()%DK+1;
            in<<p[i]<<' '<<c[i]<<'\n';
        }
        pt=0; rst.clear(); sol.clear(); ssol=0; rez=0;
        for(int i=1; i<=k; ++i) {
            pt+=p[i];
            rst.insert(p[i]+c[i]);
        }
        rez=max(rez,pt);
        for(int i=k+1; i<=n; ++i) {
            pt+=p[i];
            rst.insert(p[i]+c[i]);
            ssol+=*rst.begin();
            sol.insert(*rst.begin());
            rst.erase(rst.begin());
            bst[i]=pt-ssol;
            rez=max(rez,bst[i]);
        }
        g<<rez;
    }
    return 0;
}
