#include <iostream>
#define DN 100005
using namespace std;

int n,k,dq[DN],inc,sfc,sc,rez=DN*9,poz=-1,lg;
char s[DN];

int main()
{
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		cin>>s[i];
		if(s[i]=='*') {
			lg=0;
			inc=i+1;
			sfc=i;
			sc=0;
		}else {
			++sfc;
			if(lg<k) ++lg;
			sc+=s[i]-'0';
			if(lg==k) {
				sc-=(s[inc]-'0');
				++inc;
			}
			if(lg==k && sc<rez) {
				rez=sc;
				poz=inc;
			}
		}
		//cout<<inc<<' '<<sfc<<' '<<sc<<'\n';
	}
	if(poz!=-1) cout<<poz-1;
	else  cout<<0;
	return 0;
}
