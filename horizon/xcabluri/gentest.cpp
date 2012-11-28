#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define DN 100
using namespace std;

int n,m,fol[DN]={1},mt[DN][DN],dr[DN],sz;
int dx[]={-1,0,1};
int dy[]={ 1,1,1};

int back(int l,int c) {
	if(mt[l][c]) return 0;
	dr[++sz]=l;
	if(c==m) return 1;
	int ok=0;
	for(int d=0; d<3; ++d) if(l+dx[d]<=n && c+dy[d]<=m && l+dx[d]>0 && !mt[l+dx[d]][c+dy[d]]) ok=1;
	//cout<<l<<' '<<c<<' '<<ok<<'\n';
	cout.flush();
	if(!ok) return 0;
	int d=rand()%3;
	for(;l+dx[d]>n || c+dy[d]>m || l+dx[d]<=0 || mt[l+dx[d]][c+dy[d]]>0;d=rand()%3);
	return back(l+dx[d],c+1);
}

int main() {
	srand(time(NULL));
	for(int i=1; i<=20; ++i) {
		int cnt=0;
		char in[55],*p;
		sprintf(in,"teste/grader_test%d.in",i);
		p=in;
		freopen(in,"w",stdout);

		memset(fol,0,sizeof(fol));
		memset(mt,0,sizeof(mt));
		fol[0]=1;
		n=rand()%DN+1; m=rand()%DN+1;
		printf("%d %d\n",n,m);

		int nrc=rand()%n+1;
		for(int i=1; i<=nrc; ++i) {
			int start=0;
			sz=0;
			for(;fol[start];start=rand()%n+1);
			if(back(start,1)) {	
				++cnt;
				for(int j=1; j<=sz; ++j) mt[dr[j]][j]=cnt;
				fol[start]=1;
			}
		}
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) 
				if(mt[i][j]) printf("%2.d ",mt[i][j]);
				else printf(" 0 ");
			printf("\n");
		}
	}
}
