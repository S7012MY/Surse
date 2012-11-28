#include <iostream>
#include <fstream>
#define DN 100005
using namespace std;

int n,v[DN],poz[DN],cnt;

int main()
{
    ifstream f("intersort.in");
    ofstream g("intersort.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
        f>>v[i];
        poz[v[i]]=i;
    }
    for(int i=n; i; --i) if(poz[i]!=i) {
        if(4<min(i,v[i])) {
            swap(v[poz[1]],v[i]);
            swap(poz[1],poz[v[i]]);

            swap(v[poz[1]],v[poz[i]]);
            swap(poz[1],poz[i]);
            cnt+=2;
        }else if(poz[i]==v[poz[i]]{
            swap(v[poz[i]],v[i]);
            swap(poz[i],poz[v[i]]);
            cnt+=min(i,v[i]);
        }
    }
    g<<cnt;
    return 0;
}
