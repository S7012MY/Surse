#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#define DN 105
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN];
set<string> sol;
int n,sz,cst[DN];
map<string, int> nrm;
string nume[DN],nm,msg;
queue<int> c;

void ins(string s) {
    if(nrm.find(s)==nrm.end()) {
        nrm[s]=++sz;
        nume[sz]=s;
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>nm;
        ins(nm);
        int x=nrm[nm],nru;
        for(cin>>nru;nru--;) {
            cin>>nm;
            ins(nm);
            gr[x].push_back(nrm[nm]);
        }
    }
    cin.get();
    getline(cin,msg);
    cst[1] = msg.size()-nume[1].size()-6;
    for(c.push(1);c.size();c.pop()) {
        int fr=c.front();
        int ccur=cst[fr]+nume[fr].size()+6;
        sol.insert(nume[fr]);
        if(ccur>140) continue;
        for(it i=gr[fr].begin();i!=gr[fr].end(); ++i)
            if(0==cst[*i] || cst[*i]>ccur) {
                cst[*i]=ccur;
                c.push(*i);
            }
    }
    cout<<sol.size()<<'\n';
    for(set<string>::iterator is=sol.begin(); is!=sol.end(); ++is) cout<<*is<<'\n';
    return 0;
}
