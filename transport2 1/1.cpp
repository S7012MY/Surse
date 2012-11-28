#include <fstream>
#include <vector>
#include <bitset>
#include <cstdio>
#define DN 100001
#define DW 9000
#define x first
#define y second
#define MULT 999999
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;
int n,m;
bitset<DN> viz;
vector<per> gr[DN];

#define DIM2 8192
char vec[DIM2];
int poz;
void cit(int &x)   
{   
  x=0;   
  while(vec[poz]<'0' || vec[poz]>'9')   
       if(++poz==DIM2) fread(vec,1,DIM2,stdin),poz=0;   
  
    while(vec[poz]>='0' && vec[poz]<='9')   
    {   
        x=x*10+vec[poz]-'0';   
        if(++poz==DIM2) fread(vec, 1, DIM2, stdin),poz=0;   
    }  
}


bool dfs(int cst,int s) {
	if(s==n) return 1;
	bool o=0;
	viz[s]=1;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) 
		if(0==viz[i->x] && i->y>=cst) o|=dfs(cst,i->x);
	return o;
}

int main()
{
	freopen ("transport2.in", "r", stdin);
	//ifstream f("transport2.in");
	ofstream g("transport2.out");
	cit(n); cit(m);
	for(int i=1; i<=m; ++i) {
		int a,b,c;
		cit(a); cit(b); cit(c);
		gr[a].push_back(make_pair(b,c));
		gr[b].push_back(make_pair(a,c));
	}
	int step,i;
	for(step=1;step<=DW; step<<=1);
	for(i=0; step;step>>=1) {
		viz.reset();
		if(dfs(i+step,1)) i+=step;
	}
	g<<i;
	return 0;
}
