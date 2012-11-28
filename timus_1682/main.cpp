#include <iostream>
#include <vector>
#include <bitset>
#define DK 100005
#define DL 2*DK+100
using namespace std;

vector<int> patrate[DL];
int k,l,pre[DL],rang[DL];
bitset<DL> lst;

int find(int el) {
	int i,j;
	for(i=el;i!=pre[i]; i=pre[i]);
	while(el!=pre[el]) {
		j=pre[el];
		pre[el]=i;
		el=j;
	}
	return i;
}

void unite(int x,int y) {
    x=find(x);y=find(y);
	if(rang[x]>rang[y])//daca multimea in care e x are rang mai mare
		pre[y]=x;//unesc nodul y cu x
	else pre[x]=y; //altfel unesc pe x cu y
	if(rang[x]==rang[y])//daca rangurile sunt egale creste rangul
		++rang[y];
}

int main()
{
    cin>>k;
    l=2*k+100;
    for(int i=1;i<=l; ++i) patrate[(i*1LL*i)%k].push_back(i),pre[i]=i;
    for(int i=1; i<=l; ++i) {
        for(int x=k-(i*1LL*i)%k;x<i; x+=k) {
            lst[x]=1;
            if(x<i && find(x)==find(i)) {
               // cout<<x<<' '<<i<<'\n';
                cout<<i;
                return 0;
            }
            unite(x,i);
        }
        int u=(k-i%k)%k;
        for(int j=0; j<patrate[u].size() && patrate[u][j]<i; ++j) {
            int y=patrate[u][j];
            //cout<<i<<' '<<y<<'\n';
            if(lst[y]) continue;
            if(find(y)==find(i)) {
                //cout<<y<<' '<<i<<'\n';
                cout<<i;
                return 0;
            }
            unite(y,i);
        }
        for(int x=k-(i*1LL*i)%k;x<i; x+=k)
            lst[x]=0;
    }
    cout<<-1;
    return 0;
}
