#include <iostream>
#include <cstdlib>
#define DN 1005
using namespace std;

int n,k,pattern,lat,msk,sl[DN],sc[DN],sp[DN][DN];
char sol[DN][DN];

void afis() {
    for(int i=1; i<=lat; ++i) cout<<sol[i]+1<<'\n';
    exit(0);
}

bool check() {
    for(int i=1; i<=lat; ++i) {
        for(int j=1; j<=lat; ++j) {
            sp[i][j]=sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
            if('*'==sol[i][j]) {
                ++sl[i]; ++sc[j];
                ++sp[i][j];
            }
        }
    }
    for(int i=1; i<=lat; ++i) if(sl[i]!=k || sc[i]!=k) return 0;
    for(int i=1; i+n-1<=lat; ++i) if(1==i%n) for(int j=1; j+n-1<=lat; ++j) if(1==j%n){
        int x=i+n-1,y=j+n-1;
        if(sp[x][y]-sp[i-1][y]-sp[x][j-1]+sp[i-1][j-1]!=k) {
            //cout<<x<<' '<<y<<' '<<i<<' '<<j;
            return 0;
        }
    }
    return 1;
}

int main() {
    cin>>n>>k;
    pattern=(1<<k)-1;
    lat=n*n; msk=(1<<n)-1;
    for(int i=1; i<=lat; ++i) for(int j=1; j<=lat; ++j) sol[i][j]='.';
    if(k==0) afis();
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            //cout<<pattern<<' ';
            for(int k=1; k<=n; ++k) if(pattern&(1<<(k-1))) sol[(i-1)*n+j][(j-1)*n+k]='*';
        }
        int bit=0;
        if(pattern&(1<<(n-1))) bit=1;
        pattern=((pattern<<1)&msk)+bit;
    }
    if(!check()) {
        cout<<"NO SOLUTION\n";
        return 0;
    }
    afis();
}
