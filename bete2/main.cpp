#include <iostream>
#include <fstream>
#include <tr1/unordered_set>
#define DN 3005
using namespace std;
using namespace tr1;

unordered_set<int> mp;

int n,v[DN];

int main()
{
    ifstream f("bete2.in");
    ofstream g("bete2.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>v[i];
        mp.insert(v[i]);
    }
    int r=0;
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(mp.find(v[i]+v[j])!=mp.end())++r;
    g<<r;
    return 0;
}
