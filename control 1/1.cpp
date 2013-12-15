//O(N+M+N'^2)
//memorie cat mai putina :))
#include <fstream>
#include <bitset>
#include <list>
#include <algorithm>
#include <vector>
#define DN 250001
#define DM 3000001
#define DC 7654
using namespace std;

bitset<DN> viz;
bitset<DC> add[DC],ma[DC];
list<int> st;
int n,sz,iindex=1,nrc,la[DM],dim[DC];
vector<int> ind,lowlink,unde,sol,inc;

void tarjan(const int z) {
	ind[z]=lowlink[z]=iindex;
	++iindex;
	st.push_back(z);
	viz[z]=1;
	for(int i=inc[z];i<inc[z+1]; ++i) if(-1==ind[la[i]]) {
		tarjan(la[i]);
		lowlink[z]=min(lowlink[z],lowlink[la[i]]);
	}else if(viz[la[i]]) lowlink[z]=min(lowlink[z],lowlink[la[i]]);
	if(ind[z]==lowlink[z]) {
		int nod;
		++nrc;
		do {
			nod=st.back();
			++dim[nrc];
			unde[nod]=nrc;
			st.pop_back(); viz[nod]=0;
		}while(nod!=z);
	}
}

void ctcDoGraph() {
	st.resize(n);
	fill(ind.begin(), ind.end(),-1);
	for(int i=1; i<=n; ++i) if(-1==ind[i]) tarjan(i);
	for(int i=1; i<=n; ++i) for(int j=inc[i]; j<inc[i+1]; ++j) if(unde[i]!=unde[la[j]]) ma[unde[i]][unde[la[j]]]=1;
	st.clear();
}

void dst(int s) {
	viz[s]=1;
	for(int i=1; i<=nrc; ++i) if(ma[s][i] && 0==viz[i]) dst(i);
	st.push_front(s);
}

void tp() {
	viz&=0;
	for(int i=1; i<=nrc; ++i) if(0==viz[i]) dst(i);
}

void solve(int s) {
	sol[s]=0;
	add[s][s]=1; viz[s]=1;
	for(int i=1; i<=nrc; ++i) if(ma[s][i] && 0==viz[i]) solve(i);
	for(int i=1; i<=nrc; ++i) if(ma[s][i]) add[s]|=add[i];
	for(int i=1; i<=nrc; ++i) if(add[s][i]) sol[s]+=dim[i];
}

int main() {
	ifstream f("control.in");
	ofstream g("control.out");
	f>>n;
	inc.resize(n+2); ind.resize(n+2); lowlink.resize(n+2); unde.resize(n+2);
	inc[1]=0;
	int cont,b;
	for(int i=1; i<=n; ++i) {
		f>>cont;
		inc[i+1]=cont+inc[i];
		for(int j=0; j<cont; ++j) {
			f>>b;
			la[inc[i]+j]=b;
		}
	}
	ctcDoGraph();
	tp();
	viz&=0;
	reverse(st.begin(),st.end());
	sol.resize(nrc);
	for(list<int>::iterator i=st.begin(); i!=st.end(); ++i) if(0==viz[*i]) solve(*i);
	for(int i=1; i<=n; ++i) g<<sol[unde[i]]<<' ';
	return 0;
}
