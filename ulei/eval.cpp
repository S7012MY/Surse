#include <iostream>
#include <fstream>
#include <map>
#include <set>
#define mp make_pair
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

int n,m,t,v[1000005];
map<per,int> gr;
set<per> fol;

int main() {
	ifstream f("ulei.in");
	ifstream g("ulei.out");
	f>>t;
	for(int k=1; k<=t; ++k) {
		f>>n>>m;
		for(int i=0; i<m; ++i) {
			int a,b,c;
			f>>a>>b>>c;
			gr[mp(a,b)]=gr[mp(b,a)]=c;
		}
		g>>v[1];
		for(int i=2; ;++i) {
			g>>v[i];
			if(v[i]==-1) break;
			if(fol.find(mp(v[i-1],v[i]))!=fol.end()) {
				cout<<k<<" MUCHIE FOLOSITA DE 2 ori";
				cout.flush();
				while(1);
			}
			if(gr.find(mp(v[i-1],v[i]))==gr.end()) {
				cout<<k<<" MUCHIE inexistenta";
				cout.flush();
				while(1);
			}
			if(i>2 && gr[mp(v[i-2],v[i-1])]==gr[mp(v[i-1],v[i])]) {
				cout<<k<<" Culori identice\n";
				cout<<v[i-2]<<' '<<v[i-1]<<' '<<v[i];
				cout.flush();
				while(1);
			}
			fol.insert(mp(v[i-1],v[i]));
			fol.insert(mp(v[i],v[i-1]));
		}
		if(fol.size()!=gr.size()) {
			cout<<"MUCHII NEFOLOSITE";
			cout.flush();
			while(1);
		}

		fol.clear();
		gr.clear();
	}
}
