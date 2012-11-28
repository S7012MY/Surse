#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#define DN 21
using namespace std;

int n,v[DN],nrb[1<<DN],inq[1<<DN];
double prob[1<<DN],pt;

int count(int nr) {
    int r=0;
    do {
        r++;
    }while(nr&=(nr-1));
    return r;
}

double memo(int state) {
    queue<int> c;
    for(c.push(state);c.size();c.pop()) {
        state=c.front();
        prob[state]*=9/10;
        int s=0;
        for(int i=0; i<n; ++i) if(state&(1<<i)) s^=v[i];
        if(state) pt+=((1.0/40.0)+((s/1024.0)/20.0));
        //  cout<<s<<' '<<((1.0/40.0)+((s/1024.0)/20.0))<<'\n';
        if(!(nrb[state]&1)) {//muta batranu'
            int sp=0;//suma ponderilor
            for(int i=0; i<n; ++i) if(!(state&(1<<i))){
                int pi=(s^v[i])+1;
                sp+=pi;
            }
            for(int i=0; i<n; ++i) if(!(state&(1<<i))) {//iau cartea i
                int pr=(s^v[i])+1;
                double pi=(pr*100.0)/sp;
                prob[state|(1<<i)]+=prob[state]*pi;
                if(!inq[state|(1<<i)]) {
                    c.push(state|(1<<i));
                    inq[state|(1<<i)]=1;
                }
            }
        }else {
            for(int i=0; i<n; ++i) if(!(state&(1<<i))) {//iau cartea i
                prob[state|(1<<i)]+=prob[state];
                if(!inq[state|(1<<i)]) {
                    c.push(state|(1<<i));
                    inq[state|(1<<i)]=1;
                }
            }
        }
    }
}

int main()
{
    ifstream f("jocul2.in");
    ofstream g("jocul2.out");
    f>>n;
    for(int i=0; i<n; ++i) f>>v[i];
    for(int i=1; i<(1<<n); ++i) nrb[i]=count(i);
    prob[0]=1;
    memo(0);
    g<<fixed<<setprecision(8)<<pt;
    return 0;
}
