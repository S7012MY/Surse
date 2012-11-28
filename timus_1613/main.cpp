#include <iostream>
#include <set>
#include <string>
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
int n,a;
set<per> s;
string sol;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>a;
        s.insert(make_pair(a,i));
    }
    for(cin>>n;n--;) {
        int a,b,c;
        cin>>a>>b>>c;
        set<per>::iterator is=s.lower_bound(make_pair(c,a));
        if(is->x==c && is->y<=b) sol+='1';
        else sol+='0';
    }
    cout<<sol;
    return 0;
}
