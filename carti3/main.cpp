#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#define DN 4000005
using namespace std;

int n,c,k,cb,sz=-1,sol[DN];
deque<int> d;

void scoate(int fin=0) {
    if(fin) {
        for(;d.size();) {
            if(cb==0) {
                sol[++sz]=d.back();
                d.pop_back();
            }else {
                sol[++sz]=d.front();
                d.pop_front();
            }
        }
    }
    for(;d.size()>k;) {
        if(cb==0) {
            sol[++sz]=d.back();
            d.pop_back();
        }else {
            sol[++sz]=d.front();
            d.pop_front();
        }
    }
}

void baga(int s) {
    if(!cb) d.push_front(s);
    else d.push_back(s);
    scoate();
}

int main()
{
    ifstream f("carti3.in");
    ofstream g("carti3.out");
    f>>n>>c;
    k=DN;
    for(int i=1; i<=c; ++i) {
        int x;
        f>>x;
        d.push_back(x);
    }
    for(int i=1; i<=n; ++i) {
        int x;
        f>>x;
        if(-1==x) cb=1-cb;
        else baga(x);
    }
    scoate(1);
    for(int i=sz; i>=0; --i) g<<sol[i]<<'\n';
    return 0;
}
