#include <iostream>
#include <set>
using namespace std;

int main() {
	int n,m,p,v,rez=0;
	set<int> s1,s2,s3;
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>v;
		s1.insert(v);
	}
	cin>>m;
	for(int i=1; i<=m; ++i) {
		cin>>v;
		s2.insert(v);
	}
	cin>>p;
	for(int i=1; i<=p; ++i) {
		cin>>v;
		s3.insert(v);
	}
	for(set<int>::iterator is=s1.begin(); is!=s1.end(); ++is)
		if(s2.find(*is)!=s2.end() && s3.find(*is)!=s3.end()) ++rez;
	cout<<rez;
	return 0;
}
