#include <iostream>
#include <vector>
#define DN 100005
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;
int n,ss[DN],sj[DN];
vector<per> gr[DN];

void dfs(int s) {
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) {
        ss[i->x]=ss[s]+i->y;
        dfs(i->x);
    }
}

int main()
{
    cin>>n;
    for(int i=2; i<=n; ++i) {
        int j,c;
        cin>>j>>c;
        gr[j].push_back(make_pair(i,c));
    }
    dfs(1);
    return 0;
}
