#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string inp,rez;

string tos(int n) {
    string ret;
    for(;n;) {
        ret+=(n%10)+'0';
        n/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int main()
{
    ifstream f("compress.in");
    ofstream g("compress.out");
    f>>inp;
    int dim=1;
    for(int i=1; i<inp.size(); ++i) {
        if(inp[i]==inp[i-1]) ++dim;
        else {
            rez+=inp[i-1];
            rez.append(tos(dim));
            dim=1;
        }
    }
    rez+=inp[inp.size()-1];
    rez.append(tos(dim));
    g<<rez;
    return 0;
}
