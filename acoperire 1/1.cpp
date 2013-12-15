//matr e sim fmtm de mij
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

int n,m[205][205];

int mij[6][6]={
	{0,3,3,5,5,0},
	{1,1,3,5,6,6},
	{2,1,3,5,6,7},
	{2,1,4,8,6,7},
	{2,2,4,8,7,7},
	{0,4,4,8,8,0},
};

int main(){
	ifstream f("acoperire.in");
	ofstream g("acoperire.out");
	f>>n;
	if(n&1 || 0==n%4) {
		g<<"-1";
		return 0;
	}
	//bordez mij
	int pmij=(n>>1)-2;
	for(int i=0; i<6; ++i) for(int j=0; j<6; ++j) m[pmij+i][pmij+j]=mij[i][j];
	for(int i=pmij-2,l=10,p=8;0<i;i-=2,l+=4) {
		m[i][i+1]=m[i][i+2]=m[i+1][i+2]=m[i+2][i+2]=++p;
		int j=i+l-1;
		m[i][j-1]=m[i][j-2]=m[i+1][j-2]=m[i+2][j-2]=++p;
		int k=i+l-1;
		m[k][i+1]=m[k][i+2]=m[k-1][i+2]=m[k-2][i+2]=++p;
		m[k][j-1]=m[k][j-2]=m[k-1][j-2]=m[k-2][j-2]=++p;
		for(int ii=i+3; ii<j-4; ii+=4) {
			m[i+1][ii]=m[i][ii]=m[i][ii+1]=m[i][ii+2]=++p;
			m[i+1][ii+1]=m[i+1][ii+2]=m[i+1][ii+3]=m[i][ii+3]=++p;
			m[k-1][ii]=m[k][ii]=m[k][ii+1]=m[k][ii+2]=++p;
			m[k-1][ii+1]=m[k-1][ii+2]=m[k-1][ii+3]=m[k][ii+3]=++p;
		}
		for(int ii=i+1; ii<k; ii+=4) {
			m[ii][i+1]=m[ii][i]=m[ii+1][i]=m[ii+2][i]=++p;
			m[ii+1][i+1]=m[ii+2][i+1]=m[ii+3][i+1]=m[ii+3][i]=++p;
			m[ii][j-1]=m[ii][j]=m[ii+1][j]=m[ii+2][j]=++p;
			m[ii+1][j-1]=m[ii+2][j-1]=m[ii+3][j-1]=m[ii+3][j]=++p;
		}	
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) g<<m[i][j]<<' ';
		g<<'\n';
	}
	return 0;
}