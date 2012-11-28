#include <cstdio>
#include <map>
#define DN 400005
using namespace std;

multimap<int,int> mp;
multimap<int,int>::iterator it;
int ai[DN],q,p,v,poz[DN];

static inline int gcd(int u, int v){
    if(u == v)
        return v;
    if(0==u)
        return v;
    if(0==v)
        return u;
    if(0==(u&1)){
        if(0==(v&1))
            return (gcd((u>>1), (v>>1))<<1);
        else
            return  gcd(u>>1, v);
    }
    else if(0==(v&1))
        return gcd(u, (v>>1));
    else{
        if(u>=v)
            return gcd(((u-v)>>1), v);
        else
            return gcd(((v-u)>>1), u);
    }
}

static inline void update(int vn, int ls, int ld) {
    if(ls==ld) {
        poz[p]=vn;
        ai[vn]=v;
        return;
    }
    int m=(ls+ld)>>1,fs=(vn<<1);
    if(p<=m) update(fs,ls,m);
    else update(fs+1,m+1,ld);
    if(-1==ai[fs] || 0==ai[fs]) ai[vn]=ai[fs+1];
    else if(-1==ai[fs+1] || 0==ai[fs+1]) ai[vn]=ai[fs];
    else ai[vn]=gcd(ai[fs],ai[fs+1]);
}

static void erase(int vn) {
    ai[vn]=-1;
    for(;1;) {
        vn/=2;
        int fs=(vn<<1);
        if(-1==ai[fs] || 0==ai[fs]) ai[vn]=ai[fs+1];
        else if(-1==ai[fs+1] || 0==ai[fs+1]) ai[vn]=ai[fs];
        else ai[vn]=gcd(ai[fs],ai[fs+1]);
        if(1==vn) return;
    }
}

int main()
{
    scanf("%d\n",&q);
    for(int i=1; i<=q; ++i) {
        char c;
        scanf("%c %d\n",&c,&v);
        if(c=='+') {
            mp.insert(make_pair(v,i));
            p=i;
            update(1,1,q);
        }else {
            it=mp.find(v);
            p=it->second;
            mp.erase(it);
            v=-1;
            erase(poz[p]);
        }
        if(0==ai[1] || -1==ai[1]) printf("1\n");
        else printf("%d\n",ai[1]);
    }
    return 0;
}
