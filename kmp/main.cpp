#include <fstream>
#include <cstring>
#include <vector>
#define DN 2000005
using namespace std;

char s[DN],b[DN];
int n,pi[DN],sz,m,nrs;
vector<int> sol;

void pr() {
    for(int i=2,q=0; i<=sz; ++i) {
        for(;q!=0 && s[i]!=s[q+1];q=pi[q]);
        if(s[i]==s[q+1]) ++q;
        pi[i]=q;
    }
}

int main()
{
    ifstream f("strmatch.in");
    ofstream g("strmatch.out");
    f>>(s+1)>>(b+1);
    sz=strlen(s+1);
    m=strlen(b+1);
    pr();
    for(int i=1,q=0; i<=m; ++i) {
        for(;q!=0 && b[i]!=s[q+1];q=pi[q]);
        if(b[i]==s[q+1]) ++q;
        if(q==sz) {
            ++nrs;
            if(sol.size()<1000) sol.push_back(i-sz);
        }
    }
    g<<nrs<<'\n';
    for(int i=0 ;i<sol.size(); ++i) g<<sol[i]<<' ';
    return 0;
}
