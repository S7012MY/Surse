#include <iostream>
#include <fstream>
#include <vector>
#define DN 25
using namespace std;

vector<int> v;
int n,s[DN],rez;

int calc(vector<int> v) {
    int ret=0;
    for(int i=0; i<v.size(); ++i) {
        int vl=(i%3+1)*v[i];
        if(i&1) vl=-vl;
        ret+=vl;
    }
    return ret;
}

int main()
{
    ifstream f("max.in");
    ofstream g("max.out");
    f>>n;
    for(int i=0; i<n; ++i) f>>s[i];
    for(int sm=0; sm<(1<<n); ++sm) {
        v.clear();
        for(int i=0; i<n; ++i) if(sm&(1<<i)) v.push_back(s[i]);
        rez=max(rez,calc(v));
    }
    g<<rez;
    return 0;
}
