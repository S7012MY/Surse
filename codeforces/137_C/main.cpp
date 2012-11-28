#include <iostream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

int cnt[2][10000001];
int n,m,sus[DN],jos[DN];

void desc(int nr,int u) {
    for(int i=2; i*1LL*i<=nr; ++i)
        for(;nr%i==0;++cnt[u][i],nr/=i);
    if(nr>1) ++cnt[u][nr];
}

void d(int &nr,int u) {
    for(int i=2; i*1LL*i<=nr; ++i)
        for(;nr%i==0 && cnt[u][i]>0;--cnt[u][i],nr/=i);
    if(nr>1 && cnt[u][nr]>0) {
         --cnt[u][nr];
        nr=1;
    }
}

int main() {
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
	    cin>>sus[i];
	    desc(sus[i],0);
	}
	for(int i=1; i<=m; ++i) {
	    cin>>jos[i];
	    desc(jos[i],1);
	}
	for(int i=2; i<10000001; ++i) {
	    cnt[0][i]=min(cnt[0][i],cnt[1][i]);
	    cnt[1][i]=cnt[0][i];
	}
	for(int i=1; i<=n; ++i) {
	    d(sus[i],0);
	}
    for(int i=1; i<=m; ++i)
	    d(jos[i],1);
    cout<<n<<' '<<m<<'\n';
    for(int i=1; i<=n; ++i) cout<<sus[i]<<' ';
    cout<<'\n';
    for(int i=1; i<=m; ++i) cout<<jos[i]<<' ';
	return 0;
}
