#include <iostream>
#include <fstream>
#include <string>
#include <tr1/unordered_map>
#include <algorithm>
#include <vector>
#define DN 100005
#define x first
#define y second
using namespace std;
using namespace tr1;

int n,sz,aib[DN];
pair<int,string> op[DN];
int norm[DN];
vector<int> ind;
unordered_map<string,int> mp;

bool cmp(const int &a, const int &b) {
    if(op[a].y.size()!=op[b].y.size())
		return op[a].y.size()<op[b].y.size();
	return op[a].y<op[b].y;
}

inline int lsb(int n) {
    return (n&(n-1))^n;
}

void update(int x) {
    for(int i=x; i<=sz; i+=lsb(i)) ++aib[i];
}

int query(int x) {
	int r=0;
	for(int i=x; i>0; i-=lsb(i)) r+=aib[i];
	return r;
}

int search(int x) {
    int i,pd;
    for(pd=1;pd<=sz;pd<<=1);
    for(i=0;pd;pd>>=1) if(i+pd<=sz && x>aib[i+pd]) {
        i+=pd; x-=aib[i];
    }
	return i;
}

int conv(string s) {
    int r=0;
    for(int i=0; i<s.size(); ++i)
        r=r*10+s[i]-'0';
    return r;
}

int main()
{
    ifstream f("nums.in");
    ofstream g("nums.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>op[i].x>>op[i].y;
        if(op[i].x) ind.push_back(i);
    }
    sort(ind.begin(),ind.end(),cmp);
	sz=ind.size();
	for(int i=0; i<ind.size(); ++i) mp[op[ind[i]].y]=i+1;
    for(int i=1; i<=n; ++i) {
        if(op[i].x ) {
			int unde=mp[op[i].y];
			if(norm[unde]) continue;
            update(unde);
			norm[unde]=1;
        }
        else if(!op[i].x){
            int unde=search(conv(op[i].y));
            //cout<<unde<<' ';
            g<<op[ind[unde]].y<<'\n';
        }
		//for(int i=0; i<ind.size(); ++i) cout<<query(i+1)<<' ';
		//cout<<'\n';
    }
    return 0;
}