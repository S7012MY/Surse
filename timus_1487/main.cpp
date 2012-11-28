#include <iostream>
#include <bitset>
#define DN 1000
using namespace std;

bitset<DN> it[DN],mt[DN],viz;//inchidere tranzitiva
int n,q,st[DN],sz;
char ma[DN];

void s(int su) {
    viz[su]=1;
    for(int i=0; i<n; ++i) if(mt[su][i] && 0==viz[i]) s(i);
    st[++sz]=su;
}


int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>ma;
        for(int j=0; j<n; ++j) if('1'==ma[j]) mt[i][j]=1;
    }
    for(int i=0; i<n; ++i) if(!viz[i]) s(i);
    viz&=0;
    for(int k=sz; k>0; --k) {
        int i=st[k];
        for(int j=0; j<n; ++j) if(mt[i][j]) {
            it[j][i]=1;
            it[j]|=it[i];
        }
    }
    for(cin>>q;q;--q) {
        int a,b;
        cin>>a>>b;
        --a;--b;
        int ok=1;
        for(int i=0; i<n; ++i) if(it[a][i]==1 && it[b][i]==1) ok=0;
        if(ok) cout<<"YES\n";
        else cout<<"No\n";
    }
    return 0;
}
