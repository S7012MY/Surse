#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n,c[2],r;
char s[1005];

int main()
{
    ifstream f("swaps2.in");
    ofstream g("swaps2.out");
    f>>n>>s;
    for(int i=0; i<n; ++i) ++c[s[i]-'0'];
    for(int i=0; i<n; ++i) if(s[i]=='1' && i<c[0]) ++r;
    g<<r<<'\n';
    int punu=1;
    for(int i=0; i<n; ++i) {
        if(s[i]=='1' && i<c[0]) {
            for(;s[punu]!='0' || punu<c[0];++punu);
            g<<i+1<<' '<<punu+1<<'\n';
            ++punu;
        }
    }
    return 0;
}
