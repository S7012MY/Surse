#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string inp;
int p;
char rez[20005];

void r(int ls, int ld) {
    if(ls>ld) return;
    int lg=(ls+ld)/2;
    rez[lg]=inp[p++];
    //cout<<ls<<' '<<ld<<' '<<inp[p]<<'\n';
    if(ls!=ld) {r(ls,lg-1);r(lg+1,ld);}
}

int main()
{
    getline(cin,inp);
    int n=inp.size();
    r(0,n-1);
   // rez[p]='\0';
    for(int i=0; i<n; ++i) cout<<rez[i];
    //cout<<rez+1;
    return 0;
}
