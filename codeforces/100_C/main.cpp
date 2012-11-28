#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define DN 100005
#define x first
#define y second
using namespace std;

int n,fr[DN],nr,v[DN];
vector<vector<int> > sol;
map<int, int> mp;


set<pair<int, int>,greater<pair<int,int> > > s;
typedef set<pair<int, int>,greater<pair<int,int> > >::iterator is;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int a;
        cin>>a;
        if(mp.find(a)==mp.end()) mp[a]=++nr;
        v[i]=a;
        ++fr[mp[a]];
    }
    for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it) s.insert(make_pair(fr[it->y],it->x));
    for(bool maipot=1;maipot;) {
        vector<int> oc;
        //for(is i=s.begin(); i!=s.end(); ++i) cerr<<i->y<<' ';
        //cerr<<'\n';
        is it=s.begin();
        for(int i=1; i<=3; ++i) {
            if(it==s.end()) {
                maipot=0;
                break;
            }
            int el=it->y;
            --fr[mp[el]];
            oc.push_back(el);
            ++it;
            s.erase(s.begin());
        }
        if(maipot) {
            for(int i=0; i<3; ++i) if(fr[mp[oc[i]]])
                s.insert(make_pair(fr[mp[oc[i]]],oc[i]));
            sol.push_back(oc);
        }
    }
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i) {
        sort(sol[i].rbegin(),sol[i].rend());
        for(int j=0; j<3; ++j) cout<<sol[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
