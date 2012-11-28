#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef multiset<int>::iterator is;

int n,k;
per spec[DN];
multiset<int> post;

bool cmp(const per &a, const per&b) {
    return a.y<b.y;
}

int main()
{
    ifstream f("planificare.in");
    ofstream g("planificare.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) f>>spec[i].x>>spec[i].y;
    sort(spec+1,spec+n+1,cmp);
    for(int i=1; i<=k; ++i) post.insert(0);
    int rez=0;
    for(int i=1; i<=n; ++i) {
        is p=post.lower_bound(-spec[i].x);
        if(p!=post.end()) {
            post.erase(p);
            post.insert(-spec[i].y);
            ++rez;
        }
    }
    cout<<rez;
    g<<rez;
    return 0;
}
