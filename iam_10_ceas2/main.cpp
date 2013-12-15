#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int n,fol[30];
string a,b;
char cine[30];

int main()
{
    ifstream f("ceas2.in");
    ofstream g("ceas2.out");
    f>>a>>b;
    swap(a,b);
    if(a.size()!=b.size()) {
        g<<"NU";
        return 0;
    }
    for(char a='a'; a<='z'; ++a) cine[a-'a']=a;
    for(int i=0; i<a.size(); ++i) {
        if(a[i]!=cine[b[i]-'a']) {
            if(fol[b[i]-'a']) {
                g<<"NU";
                return 0;
            }
            else {
                fol[b[i]-'a']=1;
                cine[b[i]-'a']=a[i];
            }
        }
    }
    g<<"DA\n";
    for(char a='a'; a<='z'; ++a) if(cine[a-'a']!=a) {
        g<<a<<' '<<cine[a-'a']<<'\n';
    }
    return 0;
}
