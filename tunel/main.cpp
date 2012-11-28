#include <iomanip>
#include <fstream>
#include <vector>
#define DN 305
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int n,m,ind[DN];
double sec[DN][DN],d[DN];
vector<per> gr[DN];

void gauss() {
    ind[n]=n;
    for(int i=n-1; i>1; --i) {
        for(int j=i; j; --j) if(sec[ind[j]][i]>0) {
            swap(ind[i],ind[j]);
            break;
        }
        for(int j=1; j<i; ++j) {
            double c=sec[ind[j]][i]/sec[ind[i]][i];
            for(int k=0; k<i; ++k)
                sec[ind[j]][k]-=c*sec[ind[i]][k];
        }
    }
}

int main()
{
    ifstream f("tunel.in");
    ofstream g("tunel.out");
    f>>n>>m;
    for(int i=0; i<m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
    }
    for(int i=1; i<n; ++i) {
        d[i]=gr[i].size();
        sec[i][i]=-1;
        ind[i]=i;
        for(it j=gr[i].begin(); j!=gr[i].end(); ++j) {
            sec[i][0]-=(double)j->y/d[i];
            if(j->x!=n) sec[i][j->x]+=1/d[i];
        }
    }
    gauss();
    g<<fixed<<setprecision(9)<<sec[ind[1]][0]/sec[ind[1]][1];
    return 0;
}
