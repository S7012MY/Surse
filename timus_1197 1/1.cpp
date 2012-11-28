#include <iostream>
using namespace std;

const int dx[]={2,1,-2,-1, 2, 1,-2,-1},
		  dy[]={1,2,-1,-2,-1,-2, 1, 2};

bool check(int x, int y) {
	if(0>=x || 0>=y || 8<x || 8<y) return 0;
	return 1;
}

int main()
{
	int n,p;
	char c;
	cin>>n;
	for(int i=1; i<=n; ++i) {
		int ps=0,x,y;
		cin>>c;
		x=c-'a'+1;
		cin>>y;
		for(int d=0; d<8; ++d) if(check(x+dx[d],y+dy[d])) {
			++ps;
			//cout<<x+dx[d]<<' '<<y+dy[d]<<endl;
		}
		cout<<ps<<'\n';
	}
	return 0;
}