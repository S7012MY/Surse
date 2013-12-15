#include <iostream>
#include <fstream>
#include <vector>
#define LIM 10000000
#define x first
#define y second
#define LL long long
using namespace std;

typedef pair<int, int> per;
int s;
int sol[LIM+5];
vector<int> m[LIM+5];

void precalc() {
    for(int i=0; i<=LIM; ++i) sol[i]=LIM;
    m[1].push_back(0);
    m[1].push_back(1);
    m[2].push_back(0);m[2].push_back(1);m[2].push_back(1);
    sol[1]=1;
    int cmin=LIM;
    for(int i=3; i<=LIM; ++i) {
        m[i].push_back(0);
        m[i].push_back(1);
       // cout<<i<<'\n';
        int ok=1;
        for(int j=2; j<i && j<cmin; ++j) {
            //cout<<j<<' ';
            if(m[i-1][j-1]+m[i-1][j]<=LIM){
                m[i].push_back(m[i-1][j-1]+m[i-1][j]);
                sol[m[i][j]]=min(sol[m[i][j]],i-1);

            }else {
                ok=0;
                cmin=j;
                break;
            }
        }
        if(ok) m[i].push_back(1);
        //cout<<'\n';
    }
}

int main()
{
    ifstream f("input");
    ofstream g("output");
    precalc();
    int t;
    f>>t;
    for(int k=1; k<=t; ++k) {
        long long s;
        int rez=(1<<30);
        f>>s;
        for(int i=1; i*i<=s; ++i) if(0==s%i) {
            int st=i,dr=s/i;
            //cout<<st<<' '<<dr<<' '<<sol[st]<<' '<<sol[dr]<<' '<<sol[dr]+sol[st]<<'\n';
            if(sol[st]!=LIM && sol[dr]!=LIM) rez=min(rez,sol[dr]+sol[st]);
        }
        g<<"Case #"<<k<<": "<<rez<<'\n';
       // cout<<'\n';
    }
    return 0;
}
