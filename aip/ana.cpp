#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> per;
priority_queue<per,vector<per>,less<per> >h;
int n,k;
int main () {
	int i,el;
	freopen("ana.in","r",stdin);
	freopen("ana.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(i=1;i<=n-1;++i){
		scanf("%d",&el);
		if(i<=k)h.push(make_pair(el,i));
		else if(h.top().first>el){
			h.pop();
			h.push(make_pair(el,i));
		}
	}
	printf("%d",h.top().second);
	return 0;
} 
