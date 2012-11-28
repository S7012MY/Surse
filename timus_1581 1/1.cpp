#include <iostream>
#include <vector>
#define DN 1005
using namespace std;

int n,v[DN];
vector<int> r;

int main()
{
	cin>>n;
	int fs,cnt,prec;
	cin>>prec;
	cnt=1;
	for(int i=2; i<=n; ++i) {
		cin>>fs;
		if(prec==fs) ++cnt;
		else {
			r.push_back(cnt);
			r.push_back(prec);
			cnt=1;
		}
		prec=fs;
	}
	r.push_back(cnt); r.push_back(prec);
	for(int i=0; i<r.size(); ++i) cout<<r[i]<<' ';
	return 0;
}