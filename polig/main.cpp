#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define DN 105
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
int n,sz,c[DN],bst[DN];
per p[DN];

struct seg{
    double unghi;
    int de,la;
};

vector<seg> s;

bool cmp(seg a,seg b) {
    return a.unghi<b.unghi;
}

int main()
{
    ifstream f("polig.in");
    ofstream g("polig.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>p[i].x>>p[i].y>>c[i];
        bst[i]=-(1<<30);
    }
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) if(i!=j) {
        seg a;
        a.de=j; a.la=i;
        a.unghi=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
        s.push_back(a);
    }
    sort(s.begin(),s.end(),cmp);
    for(int i=0; i<=s.size(); ++i) bst[s[i].la]=max(bst[s[i].la],bst[s[i].de]+c[s[i].la]);
    g<<bst[0];
    return 0;
}
