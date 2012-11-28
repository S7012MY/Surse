#include <iostream>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int n,lm;
string a,b;
map<string,int> nrm;

int main()
{
    cin>>n;
    int lm=(1<<n),fmax=1;
    for(int i=0; i<lm; ++i) {
        cin>>a>>b;
        if(nrm.find(b)==nrm.end()) nrm[b]=1;
        else {
            nrm[b]=nrm[b]+1;
            fmax=max(fmax,nrm[b]);
        }
    }
    cout<<n-(int)(ceil(log((double)fmax)/log((double)2)));
    return 0;
}
