#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long l,r;
long long rez,fb=4444444444;
vector<long long> fr;

int main()
{
    cin>>l>>r;
    for(int lg=1; lg<=11; ++lg) {
        for(int i=0; i<(1<<lg); ++i) {
            long long nr=0;
            for(int j=0; j<lg; ++j) {
                nr*=10;
                if(i&(1<<j)) nr+=7;
                else nr+=4;
            }
            if(nr>=l && nr<=r) fr.push_back(nr);
            else if(nr>r) fb=min(fb,nr);
        }
    }
    if(fr.size()) {
        sort(fr.begin(),fr.end());
        rez+=(fr[0]-l+1)*fr[0];
        for(int i=1; i<fr.size();++i) rez+=(fr[i]-fr[i-1])*fr[i];
        if(fr[fr.size()-1]<r) rez+=(r-fr[fr.size()-1])*fb;
    }else {
        rez=(r-l+1)*fb;
    }
    cout<<rez;
    return 0;
}
