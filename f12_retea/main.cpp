#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>
#define DN 505
#define MULT 1000000
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;
int n,m,dmin[DN*DN][5],start,goal;
string s;

vector<per> gr[DN*DN];
queue<per> c;

int make(int i,int j) {
	return i*501+j;
}

int main() {
	ifstream f("retea.in");
	ofstream g("retea.out");
	//freopen("retea.out","w",stdout);
	f>>n>>m;
	int a,b;
	f>>a>>b;
	start=make(a,b);
	f>>a>>b;
	goal=make(a,b);
	for(int i=1; i<n+n; ++i) {
		f>>s;
		for(int j=0; j<s.size(); ++j)
			if(i&1) {
				int stanga=j,dreapta=j+1;
				int ns=make(stanga,i/2),nd=make(dreapta,i/2);
				int tp;
				if(s[j]=='-') tp=0;
				else if(s[j]=='a') tp=1;
				else tp=2;

				gr[ns].push_back(mp(nd,tp));
				gr[nd].push_back(mp(ns,tp));
			}else {
				int lc=(i-1)/2,lu=i/2;
				int ns=make((j+1)/2,lc),nd=make(j/2,lu);
				int tp;
				if(s[j]=='-') tp=0;
				else if(s[j]=='a') tp=1;
				else tp=2;
				gr[ns].push_back(mp(nd,tp));
				gr[nd].push_back(mp(ns,tp));
			}
	}
	f.close();
	for(int i=0; i<DN*DN; ++i) dmin[i][1]=dmin[i][2]=MULT;
	dmin[start][1]=dmin[start][2]=0;
	c.push(mp(start,1)); c.push(mp(start,2));
	for(;!c.empty();) {
		int fr=c.front().x,cul=c.front().y;
		c.pop();
		//cerr<<c.size()<<' ';
		for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(i->y) {
			if(cul!=i->y && dmin[i->x][i->y]>dmin[fr][cul]+1) {
				dmin[i->x][i->y]=dmin[fr][cul]+1;
                c.push(mp(i->x,i->y));
			}
		}
	}
	//cerr<<c.size();
	g<<min(dmin[goal][1],dmin[goal][2])<<'\n';
	//printf("%d",min(dmin[goal][1],dmin[goal][2]));
	g.close();
	return 0;
}
