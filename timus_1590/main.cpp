#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define DK 15
#define DN 5005
using namespace std;

char c[DN];
int sz,suf[DK][DN];//indicele in sortare al prefixului de pe poz DN si lungime 2^DK

struct sa{
    int cc,cu,poz;//cc=caracterul curent, cu caract urmator
} l[DN];

bool cmp(sa a, sa b) {
    if(a.cc=b.cc) return a.cu<b.cu;
    return a.cc<b.cc;
}

int main()
{
    cin>>c;
    sz=strlen(c);
    for(int i=0; i<sz; ++i) suf[0][i]=c[i]-'a';
    for(int k=1; (1<<k)<sz; ++k) {
        for(int i=0; i<sz; ++i) {
            l[i].cc=p[k-1][i];
            if(i+(1<<k)<sz) l[i].cc=p[k-1][i+(1<<k)];
            else l[i].cc=-1;
        }
        sort(l,l+sz,cmp);
        for(int i=0; i<sz; ++i)
            if(i==0 || l[i].cc!=l[i-1].cc || l[i].cu!=l[i-1].cu) suf[k][l[i].poz]=i;
            else suf[k][l[i].poz]=suf[k][l[i-1].p];

    }
    return 0;
}
