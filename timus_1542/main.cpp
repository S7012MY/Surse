//Paradise city
#include <iostream>
#include <string>
#include <set>
#include <cstring>
using namespace std;

typedef set<pair<int, string>, greater<pair<int, string> > >::iterator is;

struct trie {
    set<pair<int,string>,greater<pair<int, string> > >s;
    trie() {
        memset(urm,0,sizeof(urm));
        s.clear();
    }
    trie *urm[26];
};

    trie *t=new trie;

int n,cst;
string cv;

void insert(trie *u,int p) {
    if(p==cv.size()) return;
    if(!u->urm[cv[p]-'a']) u->urm[cv[p]-'a']=new trie;
    u->urm[cv[p]-'a']->s.insert(make_pair(cst,cv));
    for(;u->urm[cv[p]-'a']->s.size()>10;u->urm[cv[p]-'a']->s.erase(u->urm[cv[p]-'a']->s.end()));
    insert(u->urm[cv[p]-'a'],p+1);
}

void find(trie *u, int p) {
    if(p==cv.size()) {
        int i=1;
        for(is j=u->s.begin();j!=u->s.end() && i<11; ++i,++j) cout<<j->second<<'\n';
        return;
    }
    find(u->urm[cv[p]-'a'],p+1);
}

int main()
{
    for(cin>>n;n--;) {
        cin>>cv>>cst;
        insert(t,0);
    }
    for(cin>>n;n--;) {
        cin>>cv;
        find(t,0);
        if(n)cout<<'\n';
    }
    return 0;
}
