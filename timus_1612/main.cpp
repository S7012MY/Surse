#include <iostream>
#include <string>
#include <cctype>
#define T "tram"
#define TR "trolleybus"
using namespace std;

int main()
{
    string s;
    int ct=0,ctr=0;
    for(;cin>>s;) {
        string p;
        s+=".";
        for(int i=0; i<s.size(); ++i) {
            if(!isalpha(s[i])) {
                if(0==p.compare(T)) ++ct;
                else if(0==p.compare(TR)) ++ctr;
                p.clear();
                continue;
            }
            p+=s[i];
        }
        p.clear();
    }
    if(ct>ctr) cout<<"Tram driver";
    else if(ctr>ct) cout<<"Trolleybus driver";
    else cout<<"Bus driver";
    return 0;
}
