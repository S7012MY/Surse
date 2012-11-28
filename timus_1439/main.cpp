#include <iostream>
#include <map>
#include <set>
#define DN 100010
using namespace std;

typedef set<int>::iterator is;

int n,q,c[DN],aib[DN],dim,cine[DN];
char t[DN];
set<int> s;
map<int,int> mp;

inline int lsb(int n) {
    return (n^(n-1))&n;
}

void ins(int poz,int vl) {
    for(int i=poz; i<=dim; i+=lsb(i)) aib[i]+=vl;
}

int query(int val) {
    int ret=0,pd=1;
    for(;pd<dim;pd<<=1);
    for(;pd;pd>>=1) if(ret+pd<=dim && val>=aib[ret+pd]) {
        ret+=pd;val-=aib[ret];
        if(val==0) return ret;
    }
    return ret;
}

int deb(int poz) {
    int ret=0;
    for(int i=poz; i>0;i-=lsb(i)) ret+=aib[i];
    return ret;
}

int main()
{
    cin>>n>>q;
    for(int i=1; i<=q; ++i) {
        cin>>t[i]>>c[i];
        s.insert(c[i]);
    }
    s.insert(1000000000);
    dim=s.size();
    int lst=0,nr=1;
    for(is i=s.begin();i!=s.end(); ++i,++nr) {
        mp[*i]=nr;
        cine[nr]=*i;
        ins(nr,*i-lst);
        lst=*i;
    }

    for(int i=1; i<=q; ++i) {
        if(t[i]=='D') {
            ins(mp[c[i]]+1,-1);
        }else {
            int poz=query(c[i]);
            for(;deb(poz)>=c[i];--poz);
            cout<<poz<<' '<<deb(poz)<<' '<<c[i]<<' '<<cine[poz]+c[i]-deb(poz)<<'\n';
        }
        //cout<<deb(1)<<' '<<deb(2)<<' '<<deb(3)<<'\n';
    }
    return 0;
}
