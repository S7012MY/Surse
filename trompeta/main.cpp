#include <iostream>
#include <fstream>
using namespace std;

int n,m,vf;
char s[1000005],stk[1000005];

int main()
{
    ifstream f("trompeta.in");
    ofstream g("trompeta.out");
    f>>n>>m>>s;
    for(int i=0; i<n; ++i) {
        if(vf+n-i-1>=m) --vf;
        stk[++vf]=s[i];
    }
    printf("%s");
    return 0;
}
