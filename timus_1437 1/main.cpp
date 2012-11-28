#include <iostream>
#include <bitset>
#include <set>
#include <vector>
#define DN 260
using namespace std;

bitset<DN> pot[DN][DN];
int p[3];
set<int>s;

void memo(vector<int> x) {
   // cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<' '<<'\n';
    vector<int> n=x;
    pot[x[0]][x[1]][x[2]]=1;
    for(int i=0; i<8; ++i) {
        int sm=0;
        for(int j=0; j<3; ++j) if(i&(1<<j))sm+=x[j];
        s.insert(sm);
    }
    for(int i=0; i<3; ++i) {
        n[i]=p[i];
        if(!pot[n[0]][n[1]][n[2]]) memo(n);
        n[i]=x[i];
    }
    for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) if(i!=j) {//torn din i in j
        int cant=min(x[i],p[j]-x[j]);
        n[i]-=cant;
        n[j]+=cant;
        if(!pot[n[0]][n[1]][n[2]]) memo(n);
        n[i]+=cant;
        n[j]-=cant;
    }
}

int main()
{
    cin>>p[0]>>p[1]>>p[2];
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    memo(v);
    cout<<s.size()-1;
    return 0;
}
