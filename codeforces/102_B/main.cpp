#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string inp,rez;

int main()
{
    getline(cin,inp);
    int pp=inp.size(),beg=inp.size(),c=0,fd=-1;
    for(int i=0; i<inp.size(); ++i)
        if('.'==inp[i]) {
            pp=i;
            break;
        }else if(isdigit(inp[i])&&fd==-1) fd=i;
    if(pp) beg=pp;
    for(int i=beg-1; 0<=i&&isdigit(inp[i]); --i) {
        rez+=inp[i];
        ++c;
        if(3==c && i!=fd) {
            rez+=',';
            c=0;
        }
    }
    rez+='$';
    if(inp[0]=='-') rez+='(';
    reverse(rez.begin(), rez.end());
   // if(pp) {
        rez+='.';
        int cnt=0;
        for(int i=pp+1; i<inp.size() &&cnt<2; ++i,++cnt) rez+=inp[i];
        for(;cnt<2;++cnt) rez+='0';
   // }
    if(inp[0]=='-') rez+=')';
    cout<<rez;
    return 0;
}
