#include <iostream>
#include <string>
#include <set>
#define E "Efremov"
#define K "Kantorov"
using namespace std;

int n,m,re,rk,br;
string rez;
set<pair<string, string> > s1;
set<pair< pair<string,string> , string> >s2;

void sorts(string &n1, string &n2, string &n3) {
    string r1,r2,r3;
    r1=min(min(n1,n2),n3);
    r3=max(max(n1,n2),n3);
    if(0!=n1.compare(r1) && 0!=n1.compare(r3)) r2=n1;
    else if(0!=n2.compare(r1) && 0!=n2.compare(r3)) r2=n2;
    else r2=n3;
    n1=r1; n2=r2; n3=r3;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int c;
        string n1,n2,n3;
        cin>>c;
        if(1==c) cin>>n1;
        else if(2==c) {
            cin>>n1>>n2;
            if(n1>n2) swap(n1,n2);
            s1.insert(make_pair(n1,n2));
        }else {
            cin>>n1>>n2>>n3;
            sorts(n1,n2,n3);
            s2.insert(make_pair(make_pair(n1,n2),n3));
        }
    }
    cin>>re>>rk;
    cin>>n;
    for(int i=1; i<=n; ++i) {
        string n1=E,n2=K,n3;
        int rtg;
        cin>>n3>>rtg;
        sorts(n1,n2,n3);

        if(s2.find(make_pair(make_pair(n1,n2),n3))!=s2.end()) {
            if(0==n1.compare(E)) {
                n1=n2;
                n2=n3;
            }else if(0==n2.compare(E)) n2=n3;
            if(s1.find(make_pair(n1,n2))!=s1.end()) continue;
            if(br<rtg+re) {
                br=rtg+rk;
                if(0==n1.compare(K)) rez=n2;
                else rez=n1;
            }
        }else {
            if(br<rtg+re+rk) {
                br=rtg+re+rk;
                if(0!=n1.compare(K) && 0!=n1.compare(E)) rez=n1;
                else if(0!=n2.compare(K) && 0!=n2.compare(E)) rez=n2;
                else rez=n3;
            }
        }
    }
    if(0==br) cout<<"Fail\n";
    else cout<<"Win\n"<<rez;
    return 0;
}
