#include <iostream>
#include <fstream>
#define DN 2005
#define ULL unsigned long long
#define MULT (1ULL<<63)
using namespace std;

int n,x[DN],a[DN],b[DN];
ULL bst[DN][4]

int main()
{
    ifstream f("metrou.in");
    ofstream g("metrou.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>x[i];
    for(int i=1; i<=n; ++i) f>>a[i];
    for(int i=1; i<=n; ++i) f>>b[i];
    for(int i=1; i<=n; ++i) for(int j=0; j<4; ++j) bst[i][j]=MULT;
    ULL eai=0,ebi=0;
    for(int i=1; i<=n; ++i) {
        ULL saj=a[i],sbj=b[i];//oamenii
        ULL eaj=0,ebj=0;//costul
        if(i<n) {
            eai=a[i]*(x[i+1]-x[i]);
            ebi=b[i]*(x[i+1]-x[i]);
        }
        for(int j=i-1; j>=0; --j) {
            if(j) {
                eaj+=saj
            }
        }
    }
    return 0;
}
