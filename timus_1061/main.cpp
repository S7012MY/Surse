#include <iostream>
#define DN 100005
#define MULT 9*DN
using namespace std;

int n,k,sc,inc=1;
int rmin=MULT,rinc;
char s[DN];

int main()
{
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		cin>>s[i];
		if(s[i]=='*') {
			inc=i+1;
			sc=0;
		}else {
			sc+=s[i]-'0';
			int lg=i-inc+1;
			if(lg==k) {
			    if(sc<rmin) {
			        rmin=sc;
			        rinc=inc;
			    }
				sc-=(s[inc]-'0');
				++inc;
			}
		}
		//cout<<inc<<' '<<sfc<<' '<<sc<<'\n';
	}
	cout<<rinc;
	return 0;
}
