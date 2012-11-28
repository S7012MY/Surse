#include <iostream>
#include <string>
#include <set>
#define DN 10005
using namespace std;

string a,b;
int x,y;
set<char> s;

int main()
{
    cin>>a>>b;
    for(int i=0; i<4; ++i) {
        if(a[i]==b[i]) {
            ++x;
            a[i]='-'; b[i]='*';
        }
        s.insert(b[i]);
    }
    for(int i=0; i<4; ++i) if(a[i]!='-' && s.find(a[i])!=s.end()) ++y;
    cout<<x<<' '<<y;
    return 0;
}
