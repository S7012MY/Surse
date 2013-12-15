#include <iostream>
#include <fstream>
using namespace std;

int parse_E(char*&),parse_F(char*&),parse_T(char*&);
char e[100005];

int parse_NR(char *&pos) {
    int ans=0;
    for(;isdigit(pos[0]);ans=ans*10+pos[0]-'0',++pos);
    //cout<<pos<<'\n';
    return ans;
}

int parse_F(char *&pos) {
    int ans=0;
    if('('==pos[0]) {
       ++pos;//par deschisa
       ans=parse_E(pos);
       ++pos;//par inchisa
    }else {
        ans=parse_NR(pos);
    }
    return ans;
}

int parse_T(char *&pos) {
    int ans=parse_F(pos);
    for(;'*'==pos[0] || '/'==pos[0];) {
        if('*'==pos[0]) {
            ++pos;
            ans=ans*parse_F(pos);
        }else if('/'==pos[0]) {
            ++pos;
            ans=ans/parse_F(pos);
        }
    }
    return ans;
}

int parse_E(char *&pos) {
    int ans=parse_T(pos);
    for(;'+'==pos[0] || '-'==pos[0];) {
        if('+'==pos[0]) {
            ++pos;
            ans=ans+parse_T(pos);
        }else if('-'==pos[0]) {
            ++pos;
            ans=ans-parse_T(pos);
        }
    }
    return ans;
}

int main()
{
    ifstream f("evaluare.in");
    ofstream g("evaluare.out");
    f>>e;
    char *p=e;
    g<<parse_E(p);
    return 0;
}
