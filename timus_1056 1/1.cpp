#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#define DN 10005
#define mp make_pair
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef vector<int>::iterator it;
int n,grad[DN],cn,s1,s2,sz;
vector<int> gr[DN];
list<per> g1;

int main()
{
	cin>>n;
	if(2==n) {
		cout<<"1 2";
		return 0;
	}
	cn=n;
	for(int i=2; i<=n; ++i) {
		int a;
		cin>>a;
		gr[i].push_back(a);
		gr[a].push_back(i);
		++grad[a]; ++grad[i];
	}
	for(int i=1; i<=n; ++i) if(1==grad[i]) g1.push_back(mp(i,1)),--cn,--grad[i];
	list<per>::iterator k=g1.begin();
	for(;cn;) {
		int tc=(*k).y;
		for(;(*k).y==tc; ++k) {
			for(it i=gr[(*k).x].begin(); i!=gr[(*k).x].end(); ++i) {
				--grad[*i];
				if(1==grad[*i]) g1.push_back(mp(*i,tc+1)),--cn,--grad[*i];
			}
		}
	}
	k=g1.end();--k;
	s1=(*k).x;
	int tc=(*k).y;
	--k;
	if((*k).y==tc) s2=(*k).x;
	if(s2) {
		if(s2<s1) swap(s1,s2);
		cout<<s1<<' '<<s2;
	}else cout<<s1;
	return 0;
}
