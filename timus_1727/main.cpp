#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#define L 99999
using namespace std;

vector<int> sol;

int sd(int nr) {
    int r=0;
    for(;nr;nr/=10) r+=nr%10;
    return r;
}

int main()
{
    int n;
    cin>>n;
    for(;n;n-=sd(n)) sol.push_back(n);
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i) cout<<sol[i]<<' ';
    return 0;
}
