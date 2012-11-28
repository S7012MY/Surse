#include <iostream>
#define DN 100005
using namespace std;

int n,k,ai[DN];

void build(int vn=1,int ls=1,int ld=n) {
    if(ls==ld) {
        ai[vn]=1;
        return;
    }
    build(vn<<1,ls,(ls+ld)>>1);
    build((vn<<1)+1,((ls+ld)>>1)+1,ld);
    ai[vn]=ai[vn<<1]+ai[(vn<<1)+1];
}

void search(int ce_caut,int vn=1,int ls=1, int ld=n) {
}

int main()
{
    cin>>n>>k;
    build();
    int lp=1;
    for(int i=0; i<n; ++i) {
        int kk=k%(n-i);
        search(kk);
    }
    return 0;
}
