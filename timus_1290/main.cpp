#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef multiset<int>::iterator is;

int n;
multiset<int> s1,s2;
vector<int> sol;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int c;
        cin>>c;
        s1.insert(c);
    }
    int lst=0;
    for(;s1.size();) {
        int rq=s1.size(),d=*s1.begin()-lst;
        for(int i=1; i<=d; ++i) s2.insert(rq);
        lst=*s1.begin();
        s1.erase(s1.begin());
    }
    lst=0;
    for(;s2.size();) {
        int rq=s2.size(),d=*s2.begin()-lst;
        for(int i=1; i<=d; ++i) sol.push_back(rq);
        lst=*s2.begin();
        s2.erase(s2.begin());
    }
    for(int i=0; i<sol.size(); ++i) cout<<sol[i]<<'\n';
    return 0;
}
