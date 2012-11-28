#include <fstream>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdlib>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;
ifstream f("bal.in");
ofstream g("bal.out");

vector<int> gr[DN],gt[DN];
int n,m,grad[DN],cine[DN];
queue<int> c;
bitset<DN> fol;

void im() {
    g<<"NU";
    exit(0);
}

int main() {
    f>>n>>m;
    for(int i=0; i<m; ++i) {
        int a,b;
        f>>a>>b;
        ++grad[a];
        gr[a].push_back(b);
        gt[b].push_back(a);
    }
    for(int i=1; i<=n; ++i) if(1==grad[i]) c.push(i);
    for(;c.size(); c.pop()) {
        int fr=c.front(),cs=0;
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(!fol[*i]) {
            cs=*i;
            break;
        }
        if(!cs) im();
        cine[fr]=cs;
        fol[cs]=1;
        for(it i=gt[cs].begin(); i!=gt[cs].end(); ++i) {
            --grad[*i];
            if(1==grad[*i]) c.push(*i);
        }
    }
    for(int i=1; i<=n; ++i) if(grad[i]) im();
    g<<"DA\n";
    for(int i=1; i<=n; ++i) g<<cine[i]<<'\n';
    return 0;
}
