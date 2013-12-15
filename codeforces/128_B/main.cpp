#include <iostream>
#define DN 1005
using namespace std;

int n,m,v[DN][DN];

int cs(int a,int b) {
    int ret=0;
    if(a-2>0 && b-2>0) {
        int sum=0;
        for(int i=a-2; i<=a; ++i) for(int j=b-2; j<=b; ++j) sum+=v[i][j];
        if(sum==9) ret=1;
    }
    if(a-2>0 && b+2<=n) {
        int sum=0;
        for(int i=a-2; i<=a; ++i) for(int j=b; j<=b+2; ++j) sum+=v[i][j];
        if(sum==9) ret=1;
    }
    if(a+2<=n && b-2>0) {
        int sum=0;
        for(int i=a; i<=a+2; ++i) for(int j=b-2; j<=b; ++j) sum+=v[i][j];
        if(sum==9) ret=1;
    }
    if(a+2<=n && b+2<=n) {
        int sum=0;
        for(int i=a; i<=a+2; ++i) for(int j=b; j<=b+2; ++j) sum+=v[i][j];
        if(sum==9) ret=1;
    }
    return ret;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b,ok=0;
        cin>>a>>b;
        v[a][b]=1;
        for(int i=a-2; i<=a+2; ++i) for(int j=b-2; j<=b+2; ++j) ok|=cs(i,j);
        if(ok) {
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
