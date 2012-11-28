#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int t,n,s,p,rez,nc;

int main()
{
	ifstream f("inp.txt");
	ofstream g("out.txt");
	f>>t;
	for(int k=1; k<=t; ++k) {
		rez=0;
		f>>n>>s>>p;
		for(int i=1; i<=n; ++i) {
			f>>nc;
			int ok=0;
			for(int a=0; a<11; ++a) {
				for(int b=max(0,a-1);b<=min(a+1,10); ++b) {
					int c=nc-a-b;
					if(abs(a-b)>1 || abs(a-c)>1 || abs(b-c)>1 || c<0 || c>10 || a+b+c!=nc)
						continue;
					if(max(a,max(b,c))>=p) {
						++rez;
						ok=1;
						break;
					}
				}
				if(ok) break;
			}
			if(!s) continue;
			for(int a=0; a<11; ++a) {
				for(int b=max(0,a-2); b<=min(10,a+2); ++b) {
					int c=nc-a-b;
					if(abs(a-b)>2 || abs(a-c)>2 || abs(b-c)>2 || c<0 || c>10 || a+b+c!=nc)
						continue;
					if(max(a,max(b,c))>=p && s) {
						++rez;
						--s;
						ok=1;
						break;
					}
				}
				if(ok) break;
			}
		}
		//cout<<'\n';
		g<<"Case #"<<k<<": "<<rez<<'\n';
	}
	return 0;
}