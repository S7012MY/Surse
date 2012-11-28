#include <iostream>
#include <string>
#include <set>
#include <vector>
#define DN 80
using namespace std;

int n,t,nrc,col[DN];
string gr[DN];
vector<int> sol;

int main()
{
	for(;cin>>n;) {
		for(int i=1; i<=n; ++i) {
			cin>>gr[i];
			col[i]=0;
		}
		
		int nrcol=0;
		for(;nrcol<n;) {
			int nrm=0,nm=-1;
			for(int i=1; i<=n; ++i) {
				int nrc=0;
				if(!col[i]) ++nrc;
				for(int j=1; j<=n; ++j) if('1'==gr[i][j-1] && !col[j]) ++nrc;
				if(nrc>nrm) {
					nrm=nrc;
					nm=i;
				}
			}
			//cout<<nrm<<' '<<nm<<'\n';
			sol.push_back(nm);
			if(!col[nm]) {
				++nrcol;
				col[nm]=1;
			}
			for(int j=1; j<=n; ++j) if('1'==gr[nm][j-1] && !col[j]) {
				++nrcol;
				col[j]=1;
			}
		}
		cout<<"Case "<<++t<<": "<<sol.size();
		for(int i=0; i<sol.size(); ++i) cout<<' '<<sol[i];
		cout<<'\n';
		sol.clear();
	}
	return 0;
}
