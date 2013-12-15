#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#define x first
#define y second
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;
queue<pair<int,int> > c;
vector<int> gr[DN];
bitset<DN> viz,nn;
int n;

int main()
{
    ifstream f("nivele2.in");
    ofstream g("nivele2.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        int a,b;
        f>>a>>b;gr[a].push_back(b);
        gr[b].push_back(a);
    }
    int fs=1;
    for(c.push(make_pair(1,1));c.size();c.pop()) {
        pair<int, int> fr=c.front();
        viz[fr.x]=1;
        if(!nn[fr.y]) {
            if(!fs) g<<"\n";
            g<<"nivelul "<<fr.y<<": ";
            fs=0;
            nn[fr.y]=1;
        }
        g<<fr.x<<' ';
        for(it i=gr[fr.x].begin(); i!=gr[fr.x].end(); ++i) if(0==viz[*i]) {
            c.push(make_pair(*i,fr.y+1));
            viz[*i]=1;
        }
    }
    return 0;
}
