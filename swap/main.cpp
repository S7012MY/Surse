#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define DN 50005
using namespace std;

string a,b;
vector<int> se[26];

int n,s[DN],aib[DN],ind[DN],rez,poz[26];

bool cmp(const int &a,const int &b) {
    if(s[a]==s[b]) return a>b;
    return s[a]>s[b];
}

int lsb(int n) {
    return (n^(n-1))&n;
}

void ins(int x) {
    for(int i=x; i<=n;i+=lsb(i)) ++aib[i];
}

int query(int x) {
    int ret=0;
    for(int i=x; i>0; i-=lsb(i)) ret+=aib[i];
    return ret;
}

int main()
{
    ifstream f("swap.in");
    ofstream g("swap.out");
    f>>a>>b;
    for(int i=0; i<b.size(); ++i) se[b[i]-'a'].push_back(i);

    for(int i=0; i<a.size(); ++i) {
        ind[i+1]=i+1;
        if(poz[a[i]-'a']>=se[a[i]-'a'].size()) {
            g<<"-1";
            return 0;
        }
        s[i+1]=se[a[i]-'a'][poz[a[i]-'a']];
        ++poz[a[i]-'a'];
    }
    n=a.size();
    sort(ind+1,ind+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        rez+=query(ind[i]);
        ins(ind[i]);
    }
    g<<rez<<'\n';
    return 0;
}
