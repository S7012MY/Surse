//http://www.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
#include <iostream>
#include <fstream>
#include <cstring>
#define DN 2000005
using namespace std;

int lg[DN]={0,1};//lungimea celui mai lung palindrom cu centrul in i
char s[DN],in[DN];
int centru=1/*centrul celui mai lung palindrom la stanga*/,st,dr,n;
long long rez=1;

int main()
{
    ifstream f("pscpld.in");
    ofstream g("pscpld.out");
    f>>in;
    int lng=strlen(in);
    for(int i=0; i<lng; ++i) {
        s[++n]=in[i];
        if(i<lng-1) s[++n]='#';
    }

    for(int i=2; i<=n; ++i) {
        //min(lg[i'],
        lg[i]=min(lg[centru-(i-centru)]-1,centru+lg[centru]-i);
        lg[i]=max(lg[i],1);

        st=i-lg[i],dr=i+lg[i];
        for(;st>0 && dr<=n && s[st]==s[dr];++lg[i],--st,++dr);

        if(s[i]=='#') rez+=(lg[i]/2);
        else rez+=((lg[i]+1)/2);

        if(i+lg[i]>centru+lg[centru]) centru=i;

    }
    g<<rez;
    return 0;
}
