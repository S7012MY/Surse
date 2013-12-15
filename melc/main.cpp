#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<pair<double,double>, int> per;
per p[1005];
int n;
double aa,bb;

double tg(double x,double y) {
    if (x==aa) return 1000000000;
    return 1.0*(y-bb)/(x-aa);
}

bool cmp(const per &a, const per &b) {
    if(a.first.first>=aa && b.first.first<aa) return 1;
    if(a.first.first<aa && b.first.first>=aa) return 0;
    return tg(a.first.first,a.first.second)<tg(b.first.first,b.first.second);
}

int main()
{
    ifstream f("melc.in");
    ofstream g("melc.out");
    cin>>aa>>bb;
    cin>>n;
    for(int i=1; i<=n; ++i) {
        double a,b,c;
        cin>>a>>b>>c;
        p[i]=make_pair(make_pair(a,b),c);
    }
    sort(p+1,p+n+1,cmp);
    cout<<"0\n";
    for(int i=1; i<=n; ++i) cout<<p[i].second<<'\n';
    cout<<'0';
    return 0;
}
