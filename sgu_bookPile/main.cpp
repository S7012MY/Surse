#include <iostream>
#include <string>
#include <deque>
#define DN 4000005
using namespace std;

int n,m,k,cb,sz=-1;
string sol[DN];
deque<string> d;

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

void baga(string s) {
    if(!cb) d.push_front(s);
    else d.push_back(s);
    scoate();
}

int main()
{
    cin>>n>>m>>k;
    cin.get();
    for(int i=1; i<=n; ++i) {
        string c;
        getline(cin,c);
        d.push_back(c);
    }
    scoate();
    for(int i=1; i<=m; ++i) {
        string op,c;
        getline(cin,op);
        if(op.compare("ROTATE")==0) {
            cb=1-cb;
            continue;
        }
        int j;
        for(j=0; op[j]!='('; ++j);
        ++j;
        for(;op[j]!=')';c+=op[j],++j);
        baga(c);
    }
    scoate(1);
    for(int i=sz; i>=0; --i) cout<<sol[i]<<'\n';
    return 0;
}
