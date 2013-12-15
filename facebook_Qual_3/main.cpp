#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int frq[30],t;

string s;

int main()
{
    ifstream f("input");
    ofstream g("output");
    f>>t;
    f.get();
    for(int k=1; k<=t; ++k) {
        getline(f,s);
        int rez=0;
        for(int i=0; i<30; ++i) frq[i]=0;
        for(int i=0; i<s.size(); ++i) if(isalpha(s[i]))
            ++frq[s[i]-'A'];
        rez=frq['H'-'A'];
        rez=min(rez,frq[0]);
        rez=min(rez,frq['C'-'A']/2);
        rez=min(rez,frq['K'-'A']);
        rez=min(rez,frq['E'-'A']);
        rez=min(rez,frq['R'-'A']);
        rez=min(rez,frq['U'-'A']);
        rez=min(rez,frq['P'-'A']);
        cout<<"Case #"<<k<<": "<<rez<<'\n';
        g<<"Case #"<<k<<": "<<rez<<'\n';
    }
    return 0;
}
