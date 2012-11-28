#include <iostream>
#include <fstream>
#include <vector>
#define DN (1<<20)
using namespace std;

int n,sz,msk;
char sol[DN];
vector<int> gr[DN];

void euler(int s) {
    sol[sz++]=(s&1)+'0';
    for(;gr[s].size();) {
        int i=gr[s].back();
        gr[s].pop_back();
        euler(i);
    }
}

int main()
{
    ifstream f("biti.in");
    ofstream g("biti.out");
    f>>n;
    --n;
    msk=(1<<n)-1;
    for(int i=0; i<=msk; ++i) {
        int nn=((i<<1)&msk);
        gr[i].push_back(nn+1);
        gr[i].push_back(nn);
    }
    for(int i=1; i<n; ++i) sol[sz++]='0';
    euler(0);
    g<<sz<<'\n'<<sol;
    return 0;
}
