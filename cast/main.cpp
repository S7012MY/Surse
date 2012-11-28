#include <iostream>
#include <fstream>
#include <vector>
#define DN 13
#define MULT (1<<30)
using namespace std;

int t,n,lg[DN][DN],bst[DN][1<<DN];

int memo(int s, int state) {
    if(bst[s][state]!=MULT) return bst[s][state];
    vector<int> v;
    for(int i=0; i<n; ++i) if((state&(1<<i)) && i!=s) v.push_back(i);
    for(int i=0; i<(1<<v.size()); ++i) {
        int sm=0;
        for(int j=0; j<v.size(); ++j) if(i&(1<<j)) sm|=(1<<v[j]);
        for(int j=0; j<v.size(); ++j) if(i&(1<<j))
            bst[s][state]=min(bst[s][state],max(lg[s][v[j]]+memo(v[j],sm),lg[s][v[j]]+memo(s,state^sm)));
    }
    return bst[s][state];
}

int main()
{
    ifstream f("cast.in");
    ofstream g("cast.out");
    for(f>>t;t;--t) {
        f>>n;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) f>>lg[i][j];
            for(int j=0; j<(1<<n); ++j) bst[i][j]=MULT;
            bst[i][1<<i]=0;
        }
        g<<memo(0,(1<<n)-1)<<'\n';
    }
    return 0;
}
