#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#define DN (1<<18)
using namespace std;

int n,k,v[DN];
map<int,int> cnt;

int main()
{
    ifstream f("facebook.in");
    ofstream g("facebook.out");
    f>>n>>k;
    int poz=0;
    for(int i=1; i<=n; ++i) {
        f>>v[i];
        ++cnt[v[i]];
        if(cnt[v[i]]==k) {
            poz=i;
            break;
        }
    }
    if(poz) g<<poz-k;
    else g<<-1;
    return 0;
}
