#include <iostream>
#include <fstream>
#include <set>
#define DN 2000005
using namespace std;

set<pair<int,int> > s;
typedef set<pair<int,int> >::iterator is;
//bitset<DN> fol;

int t,a,b;

int main()
{
	ifstream f("inp.txt");
	ofstream g("out.txt");
	f>>t;
	for(int i=1; i<=t; ++i) {
		s.clear();
		f>>a>>b;
		int rez=0;
		for(int i=a; i<=b; ++i) {
			int ci=i,nrc=0,pz=1,nr2;
			for(;ci;++nrc,ci/=10,pz*=10);
			pz/=10;
			//cout<<pz<<'\n';
			//cin>>t;
			ci=i;
			for(int k=1; k<=10; ++k) {
				ci=(ci/pz+ci*10)%(pz*10);
				int cci=ci,nr2=0;
				for(;cci;++nr2,cci/=10);
				if(ci!=i && nrc==nr2 && ci<=b && ci>=a) {
					s.insert(make_pair(min(i,ci),max(i,ci)));
					//cout<<i<<' '<<ci<<'\n';
				}
			}
			//for(is k=s.begin(); k!=s.end(); ++k) cout<<k->first<<' '<<k->second<<'\n';
		}
		//cin>>rez;
		g<<"Case #"<<i<<": "<<s.size()<<'\n';
	}
	return 0;
}