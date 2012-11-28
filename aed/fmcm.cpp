#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define DN 411
#define MULT 0x3f3f3f3f
#define deb(n) fprintf(stderr,"%d",(n))
using namespace std;

vector< pair<int, int> > graf[DN];
vector< pair<int, int> >::iterator it;
bitset<DN> viz;
int n,m,sursa,dest,dist[DN],flux[DN];
int c[DN][DN];//capacitate

class cmp{
public :
	inline bool operator() ( const int& x, const int& y ) {
        return dist[x] > dist[y];
    }
};


priority_queue<int ,vector<int>,cmp> heap;

bool b() {
	int x,y,cost;
	fill(dist+1,dist+n+1,MULT);
	flux[sursa]=dist[sursa]=0;
	viz.flip(sursa);//schimba valoarea bitului de pe poz sursa
	for(heap.push(sursa);!heap.empty(); ){
		x=heap.top();
		heap.pop();
		viz.flip(x);
		for(it=graf[x].begin(); it!=graf[x].end();++it){
			y=it->first; cost=it->second;
			if(sursa==y) continue;
			if(c[x][y]>0 && dist[y]>dist[x]+cost) {
				flux[y]=x;
				dist[y]=dist[x]+cost;
				if(!viz.test(y)) {
					heap.push(y);
					viz.flip(y);
				}
			}
		}
	}
	viz&=0;
	return dist[dest]!=MULT;
}

int main()
{
	int x,y,co,rez;
	freopen("fmcm.in","r",stdin);
	freopen("fmcm.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&sursa,&dest);
	for(int i=1; i<=m;++i) {
		scanf("%d %d",&x,&y);
		scanf("%d %d",&c[x][y],&co);
		graf[x].push_back(make_pair(y,co));
		graf[y].push_back(make_pair(x,-co));
	}
	for(rez=0;b();rez+=co*dist[dest]) {
		co=MULT;
		for(x=dest;flux[x];x=flux[x]) co=min(co,c[flux[x]][x]);
		for(x=dest;flux[x];x=flux[x]) {
			c[flux[x]][x]-=co;
			c[x][flux[x]]+=co;
		}
	}
	printf("%d",rez);
	return 0;
}

