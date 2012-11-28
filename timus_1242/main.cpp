#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN],gt[DN];
int n,viz[DN];
string s;

void dfs(int s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==viz[*i]) dfs(*i);
}

void dft(int s) {
    viz[s]=1;
    for(it i=gt[s].begin(); i!=gt[s].end(); ++i) if(0==viz[*i]) dft(*i);
}

int main()
{
    cin>>n;
    cin.get();
    for(getline(cin,s);s.compare("BLOOD");getline(cin,s)) {
        int a,b,i=0;
        a=b=0;
        for(;isdigit(s[i]);a=a*10+s[i]-'0',++i);
        for(;!isdigit(s[i]);++i);
        for(;isdigit(s[i]);b=b*10+s[i]-'0',++i);
        gr[a].push_back(b);
        gt[b].push_back(a);
    }
    int nr;
    for(;cin>>nr;) {
        dfs(nr);
        dft(nr);
    }
    bool ok=0;
    for(int i=1; i<=n; ++i) if(0==viz[i]) cout<<i<<' ',ok=1;
    if(0==ok) cout<<0;
    return 0;
}
