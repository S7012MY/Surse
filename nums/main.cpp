#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#define DN 100005
#define x first
#define y second
using namespace std;

int n,ind[DN],sz,aib[DN];
pair<int,string> op[DN];
int norm[DN];
map<string,int> mp;

bool cmp(const int &a, const int &b) {
    if(!op[a].x) return 0;
    if(!op[b].x) return 1;
    if(op[a].y.size()==op[b].y.size()) return op[a].y.compare(op[b].y)<0;
    return op[a].y.size()<op[b].y.size();
}

inline int lsb(int n) {
    return ((n^(n-1))&n);
}

void update(int x) {
    for(int i=x; i<=sz; i+=lsb(i)) ++aib[i];
}

int c(int s) {
    int i,st=1;
    for(;st<sz; st<<=1);
    for(i=0;st;st>>=1) if(i+st<=sz && s>=aib[i+st]) {
        i+=st;s-=aib[i];
        if(0==s) return i;
    }
    return -1;
}

int conv(string s) {
    int r=0;
    for(int i=0; i<s.size(); ++i)
        r=r*10+s[i]-'0';
    return r;
}

int query(int x) {
    int r=0;
    for(int i=x; i>0; i-=lsb(i)) r+=aib[i];
    return r;
}

int main()
{
    ifstream f("nums.in");
    ofstream g("nums.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>op[i].x>>op[i].y;
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,cmp);
    for(int i=1;op[ind[i]].x && i<=n; ++i) if(mp.find(op[ind[i]].y)==mp.end()) {
        mp[op[ind[i]].y]=i;
        ++sz;
    }
   // for(int i=1; i<=n; ++i) g<<op[ind[i]].x<<' '<<op[ind[i]].y<<'\n';
    //for(int i=1; i<=n; ++i) cout<<norm[i]<<' '<<op[i].x<<' '<<op[i].y<<'\n';
    for(int i=1; i<=n; ++i) {
        if(op[i].x && mp[op[i].y]!=-1) {
            update(mp[op[i].y]);
           // g<<mp[op[i].y]<<' '<<i<<'\n';
            mp[op[i].y]=-1;
        }
        else if(!op[i].x){
            int ce=conv(op[i].y);
            int unde=c(ce);
            //g<<ce<<' '<<unde<<' '<<i<<'\n';
            //cout<<unde<<' ';
            g<<op[ind[unde]].y<<'\n';
        }
    }
    return 0;
}
