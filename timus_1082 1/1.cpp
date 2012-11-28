#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> per;
char m[17][17];
vector<per> f,s;
vector<char> rez;

int main()
{
	char c;
	for(int i=0; i<4; ++i) for(int j=0;j<4; ++j) {
		cin>>c;
		if('X'==c) f.push_back(make_pair(i,j));
	}
	for(int i=0; i<4; ++i) for(int j=0;j<4; ++j) cin>>m[i][j];
	for(int i=0; i<4; ++i) {
		for(int i=0; i<f.size(); ++i) {
			rez.push_back(m[f[i].first][f[i].second]);
			s.push_back(make_pair(f[i].second,3-f[i].first));
		}
		sort(s.begin(),s.end());
		//for(int i=0; i<s.size(); ++i) cout<<s[i].first<<' '<<s[i].second<<"|";
		//cout<<endl;
		f=s;
		s.clear();
	}
	for(int i=0; i<rez.size(); ++i) cout<<rez[i];
	return 0;
}