#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <string>
#define DN 305
#define special "Isenbaev"
#include <queue>
using namespace std;

typedef vector<int>::iterator it;
typedef set<string>::iterator is;

int n,rez[DN];
vector<string> v1,v2,v3;
vector<int> gr[DN];
set<string> s;
map<string, int> ind;
queue<int> c;

void bfs() {
	for(c.push(ind[special]);c.size(); c.pop()) {
		int nc=c.front();
		for(it i=gr[nc].begin(); i!=gr[nc].end(); ++i) if(0==rez[*i]) {
			rez[*i]=rez[nc]+1;
			c.push(*i);
		}
	}
}

int main()
{
	cin>>n;
	string s1,s2,s3;
	for(int i=1; i<=n; ++i) {
		cin>>s1>>s2>>s3;
		s.insert(s1);s.insert(s2);s.insert(s3);
		v1.push_back(s1); v2.push_back(s2); v3.push_back(s3);
	}
	int z=1;
	for(is i=s.begin(); i!=s.end(); ++i) {
		ind[*i]=z; ++z;
	}
	for(int i=0; i<n; ++i) {
		gr[ind[v1[i]]].push_back(ind[v2[i]]);
		gr[ind[v1[i]]].push_back(ind[v3[i]]);
		gr[ind[v2[i]]].push_back(ind[v1[i]]);
		gr[ind[v2[i]]].push_back(ind[v3[i]]);
		gr[ind[v3[i]]].push_back(ind[v1[i]]);
		gr[ind[v3[i]]].push_back(ind[v2[i]]);
	}
	bfs();
	z=1;
	rez[ind[special]]=0;
	for(is i=s.begin(); i!=s.end(); ++i) {
		if(*i!=special && 0==rez[z]) {
			cout<<*i<<' '<<"undefined\n";
			++z;
			continue;
		}
		cout<<*i<<' '<<rez[z++]<<'\n';
	}
	return 0;
}
