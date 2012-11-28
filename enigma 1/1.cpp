#include <iostream>
#include <fstream>
#include <cstring>
#define DL 300005
#define DS 105
#define MOD 31333
using namespace std;

struct trie {
	int nrc;
	trie *urm[26];
	trie() {
		nrc=0;
		memset(urm,0,sizeof(urm));
	}
};

trie *t=new trie;
int n,m,dp[DL],i,lg;
char s[DL],sm[DS];

void ins(trie *t,int nrs) {
	if(nrs>1) ++t->nrc;
	if(nrs>lg) return;
	int nxt=sm[nrs]-'a';
	if(0==t->urm[nxt]) t->urm[nxt]=new trie;
	ins(t->urm[nxt],nrs+1);
}

void find(trie *t, int nrs) {
	if((t->nrc)>0) dp[i+nrs-1]=(dp[i+nrs-1]+dp[i]*(t->nrc))%MOD;
	if(i+nrs>n) return;
	int nxt=s[i+nrs]-'a';
	if(0==t->urm[nxt]) return;
	find(t->urm[nxt],nrs+1);
}

int main()
{
	ifstream f("enigma.in");
	ofstream g("enigma.out");
	f>>n>>m>>s+1;
	for(int i=0; i<m; ++i) {
		f>>sm+1;
		//cout<<sm+1;
		lg=strlen(sm+1);
		ins(t,1);
	}
	dp[0]=1;
	for(i=0; i<n; ++i) if(0<dp[i]) find(t,1);
	g<<dp[n];
	return 0;
}
