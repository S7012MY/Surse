#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#define DN 100005
#define DM 500001
#define x first
#define y second
#include <bitset>
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

pair<int,per> lst[DM];
int n,m,pre[DM],rb;
long long tcost;
set<pair<long long,int> ,greater<pair<long long,int> > >s;
vector<per> gr[DN];
bitset<DN> fol;

int find(int el) {
	int i,j;
	for(i=el;i!=pre[i]; i=pre[i]);//cautam un nod care e indreptat spre el
	while(el!=pre[el]) {
		j=pre[el];
		pre[el]=i;
		el=j;
	}
	return i;
}

void unite(int i,int j) {
    pre[find(i)]=find(j);
}

void baga(int nod) {
    fol[nod]=1;
    for(it i=gr[nod].begin(); i!=gr[nod].end(); ++i) if(!fol[i->x]) {
        s.insert(make_pair(i->y,i->x));
        //cerr<<i->x<<' ';
    }
    //cerr<<'\n';
}

int main()
{
    int i;
    ifstream f("aparare.in");
    ofstream g("aparare.out");
    f>>n>>m;
    for(i=1; i<=m; i++) {
        f>>lst[i].y.x>>lst[i].y.y>>lst[i].x;
    }
    for(i=1; i<=n; i++) pre[i]=i;
    sort(lst+1,lst+m+1);

    for(i=1;i<=m; i++)
        if(find(lst[i].y.x)!=find(lst[i].y.y)) {
            tcost+=lst[i].x;
            unite(lst[i].y.x,lst[i].y.y);
            gr[lst[i].y.x].push_back(make_pair(lst[i].y.y,lst[i].x));
            gr[lst[i].y.y].push_back(make_pair(lst[i].y.x,lst[i].x));
        }
    for(int i=n/2; i<=n; ++i) {
        fol&=0;
        s.clear();
        int r2=0;
        baga(i);
        for(int j=1; j<5; ++j) {
            r2+=s.begin()->x;
            int nc=s.begin()->y;
            //cerr<<nc<<' ';
            s.erase(s.begin());
            baga(nc);
        }
        rb=max(rb,r2);
    }
    g<<tcost<<' '<<tcost-rb;
    return 0;
}
