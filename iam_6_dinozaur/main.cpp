#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int fr[30];
string s;

int main()
{
    ifstream f("dinozaur.in");
    ofstream g("dinozaur.out");
    f>>s;
    for(int i=0; i<s.size(); ++i) {
        ++fr[s[i]-'a'];
        if(fr[s[i]-'a']>1) {
            g<<"1\n";
            return 0;
        }
    }
    g<<"0\n";
    return 0;
}
