#include <fstream>
#define DN 100005
using namespace std;

int n,a,b,s[DN],rez,fr[DN];

int cb(int el) {
    if(el<0) return 0;
    return fr[el];
}

int main()
{
    ifstream f("teams.in");
    ofstream g("teams.out");
    f>>n>>a>>b;
    for(int i=1; i<=n; ++i) {
        f>>s[i];
        ++fr[s[i]];
    }
    for(int i=1; i<=33000; ++i) fr[i]+=fr[i-1];
    for(int i=1; i<=n; ++i) {
        rez+=cb(b-s[i])-cb(a-s[i]-1);
        if(s[i]<=b-s[i]) --rez;
        if(s[i]<=a-s[i]-1) ++rez;
    }
    g<<rez/2;
    return 0;
}
