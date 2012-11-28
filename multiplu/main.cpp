#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <set>
using namespace std;

    ifstream f("multiplu.in");
    ofstream g("multiplu.out");

int a,b,m,mm[2000005],prec[2000005],cur[2000005];
struct trei {
    int pr,c,md;
};
queue<trei> c;

int cmmdc(int a, int b) {
    int c;
    for(;b;) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

void af(int ind) {
    if(prec[ind]!=0) af(prec[ind]);
    g<<cur[ind];
}

int main()
{
    f>>a>>b;
    m=(a*b)/cmmdc(a,b);
    int ind=1;
    trei fr,nxt;
    fr.c=1; fr.pr=0; fr.md=1;
    for(c.push(fr);c.size(); c.pop(),++ind) {
        fr=c.front();
        cur[ind]=fr.c;
        prec[ind]=fr.pr;
        int mc=fr.md;
        if(mm[mc]) continue;
        mm[mc]=1;
        if(mc==0) {
            af(ind);
            return 0;
        }
        int md=(mc*10)%m;
        nxt.md=md;
        nxt.c=0;
        nxt.pr=ind;
        c.push(nxt);
        nxt.md=(md+1)%m;
        nxt.c=1;
        c.push(nxt);
    }
    return 0;
}
