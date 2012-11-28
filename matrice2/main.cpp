#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <algorithm>
#define DN 305
#define DP 90005
#define DV 1000005
using namespace std;

typedef vector<int>::iterator it;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

vector<pair<int, pair<int, int> > > vals;
bitset<DV> z;
int n,q,cod[DN][DN],m[DN][DN],pre[DP];

void find(int s) {
}

int main()
{
    ifstream f("matrice.in");
    ofstream g("matrice.out");
    f>>n>>q;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        int x;
        f>>x;
        m[i][j]=x;
        vals.push_back(make_pair(x,make_pair(i,j)));
    }
    sort(vals.rbegin(),vals.rend());

    for(int i=0; i<vals.size(); ++i) {
        for(int d=0; d<4; ++d)
    }
    return 0;
}
