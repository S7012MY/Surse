#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <set>
#define DN 1000005
using namespace std;

int s,k;
long long nr[DN],sp[DN],bun[DN],cnt,sol[DN],sz;
set<int> c;

void back(int nr,int p) {
    if(nr==0) {
        if(sz==1) {
            cout<<"2\n0 "<<sol[sz];
            exit(0);
        }
        cout<<sz<<'\n';
        for(int i=1; i<=sz; ++i) cout<<sol[i]<<' ';
        exit(0);
    }
   // if(c.find(nr)==c.end()) return;
    for(int i=p-1; i>0; --i) if(bun[i]<=nr) {
        //cout<<bun[i]<<' ';
        sol[++sz]=bun[i];
        c.erase(bun[i]);
        back(nr-bun[i],i);
        --sz;
        c.insert(bun[i]);
    }
}

int main()
{
    cin>>s>>k;
    nr[1]=1;
    sp[1]=1;
    for(int i=2; nr[i-1]<=s; ++i) {
        nr[i]=sp[i-1]-sp[max(i-k-1,0)];
        sp[i]=sp[i-1]+nr[i];
        //cout<<nr[i]<<' ';
        bun[++cnt]=nr[i];
        //cout<<nr[i]<<' ';
        c.insert(nr[i]);
    }
    //reverse(bun+1,bun+cnt+1);
    back(s,cnt+1);
    cout<<-1;
    return 0;
}
