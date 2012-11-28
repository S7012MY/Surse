#include <fstream>
#include <set>
using namespace std;

int n,m,nrc,cam;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int mt[200][200],fin[200][200],ce[200][200];
int r1,rezx,rezy,rez;
set<int> s;

bool check(int a,int b) {
	return (a>0 && b>0 && a<=n && b<=m);
}

void dfs(int a,int b) {
	mt[a][b]=-1;
	++nrc;
	for(int d=0; d<4; ++d) {
		int ii=a+dx[d],jj=b+dy[d];
		if(check(ii,jj) && !mt[ii][jj]) dfs(ii,jj);
	}
}

void sset(int a,int b){
	fin[a][b]=nrc;
	ce[a][b]=cam;
	for(int d=0; d<4; ++d) {
		int ii=a+dx[d],jj=b+dy[d];
		if(check(ii,jj) && -1==mt[ii][jj] && !fin[ii][jj]) sset(ii,jj);
	}
}

int main() {
	ifstream f("vila.in");
	ofstream g("vila.out");
	f>>n>>m;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
		char c;
		f>>c;
		if(c=='1') mt[i][j]=1;
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(!mt[i][j]) {
		nrc=0;
		++cam;
		dfs(i,j);
		sset(i,j);
		r1=max(r1,nrc);
	}
	
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(1==mt[i][j]){
		int ct=1;
		for(int d=0; d<4; ++d) {
			int ii=i+dx[d],jj=j+dy[d];
			if(s.find(ce[ii][jj])==s.end()) {
				ct+=fin[ii][jj];
				s.insert(ce[ii][jj]);
			}
		}
		s.clear();
		if(ct>rez) {
			rez=ct;
			rezx=i,rezy=j;
		}
	}
	g<<cam<<'\n'<<r1<<'\n'<<rezx<<' '<<rezy<<' '<<rez;
	return 0;
}