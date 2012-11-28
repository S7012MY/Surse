#include <iostream>
#include <vector>
#include <algorithm>
#define DN 1005
using namespace std;

typedef pair<int,int> per;

int n,m[DN][DN],c[DN];
vector<pair<per,per> > v;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>c[i];
    }
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=c[i]; ++j) cin>>m[i][j];
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=c[i]; ++j) {
            per pbst;
            int bst=(1<<30);
            for(int k=i; k<=n; ++k) for(int l=(k==i)?(j+1):1; l<=c[k]; ++l)
                if(bst>m[k][l]) {
                    bst=m[k][l];
                    pbst=make_pair(k,l);
                }
            if(bst==(1<<30) || bst>=m[i][j]) continue;
            swap(m[i][j],m[pbst.first][pbst.second]);
            v.push_back(make_pair(make_pair(i,j),make_pair(pbst.first,pbst.second)));
        }
    }
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); ++i) {
        cout<<v[i].first.first<<' '<<v[i].first.second<<' ';
        cout<<v[i].second.first<<' '<<v[i].second.second<<'\n';
    }
   /* for(int i=1; i<=n; ++i) {
        for(int j=1; j<=c[i]; ++j) cout<<m[i][j]<<' ';
        cout<<'\n';
    }*/
    return 0;
}
