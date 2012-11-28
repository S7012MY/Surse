#include <iostream>
#include <algorithm>
#define DN 20005
#define DK 15
#define MOD 1000000000
using namespace std;

int n,k,v[DN],aib[DN][DK],ind[DN],rez;

bool cmp(const int &a,const int &b) {
    return v[a]>v[b];
}

int lsb(int x) {
    return (x^(x-1))&x;
}

void ins(int x,int k, int vl) {
    for(int i=x; i<=n; i+=lsb(i)) aib[i][k]=(aib[i][k]+vl)%MOD;
}

int query(int x,int k) {
    int r=0;
    for(int i=x; i>0; i-=lsb(i)) {
        r+=aib[i][k];
        r%=MOD;
    }
    return r;
}

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        ind[i]=i;
    }
    sort(ind+1,ind+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        int rq=0;
        for(int j=1; j<k; ++j) {
            rq=query(ind[i]-1,j);
            //cout<<v[ind[i]]<<' '<<j+1<<' '<<rq<<'\n';
            ins(ind[i],j+1,rq);
        }
        ins(ind[i],1,1);
        //cout<<query(ind[i],k)<<' ';
    }
    cout<<query(n,k);
    return 0;
}
