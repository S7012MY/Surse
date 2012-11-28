#include <iostream>
#include <fstream>
#include <set>
using namespace std;

multiset<int> s;
int n,k,x,lst,cit;
long long sumLeft;

int main()
{
    ifstream f("bleach.in");
    ofstream g("bleach.out");
    f>>n>>k;
    for(int i=1; i<=min(2005,n); ++i) {
        f>>x;
        ++cit;
        s.insert(x);
    }
    for(int i=1; i<=n; ++i) {
        if(sumLeft<*s.begin()) {
            lst+=*s.begin()-sumLeft;
            sumLeft=*s.begin();
        }
        sumLeft+=*s.begin();
        s.erase(s.begin());
        if(cit<n) {
            ++cit;
            f>>x;
            s.insert(x);
        }
    }
    for(;s.size();s.erase(s.begin())) {
        if(sumLeft<*s.begin()) {
            lst+=*s.begin()-sumLeft;
            sumLeft=*s.begin();
        }
        sumLeft+=*s.begin();
    }
    g<<lst;
    return 0;
}
