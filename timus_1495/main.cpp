#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

int m,mm[2000005],prec[2000005],cur[2000005];
struct trei {
    int pr,c,md,lg;
};
queue<trei> c;

void af(int ind) {
    if(prec[ind]!=0) af(prec[ind]);
    cout<<cur[ind];
}

int main()
{
    cin>>m;
    int ind=1;
    trei fr,nxt;
    fr.pr=0;
    fr.c=fr.md=fr.lg=1;
    fr.md%=m;
    c.push(fr);
    fr.c=fr.md=2;
    fr.md%=m;
    c.push(fr);
    for(;c.size(); c.pop(),++ind) {
        fr=c.front();
       // cout<<fr.lg<<' ';
        if(fr.lg>30) {
            cout<<"Impossible";
            return 0;
        }
        cur[ind]=fr.c;
        prec[ind]=fr.pr;
        int mc=fr.md;
        if(mm[mc]) continue;
        mm[mc]=1;
        if(mc==0) {
            af(ind);
            return 0;
        }
        int md=((mc*10)+1)%m;
        nxt.lg=fr.lg+1;
        nxt.md=md;
        nxt.c=1;
        nxt.pr=ind;
        c.push(nxt);
        nxt.md=(md+1)%m;
        nxt.c=2;
        c.push(nxt);
    }
    cout<<"Impossible";
    return 0;
}
