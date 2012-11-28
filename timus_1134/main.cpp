#include <iostream>
#include <algorithm>
using namespace std;

int n,m,v[1005],frq[1000005];

int main()
{
    cin>>n>>m;
    if(n<m) {
        cout<<"NO";
        return 0;
    }
    for(int i=1; i<=m; ++i) cin>>v[i];
    sort(v+1,v+m+1);
    for(int i=1; i<=m; ++i) {
        if(v[i]>n) {
            cout<<"NO";
            return 0;
        }
        if(v[i]==0 ) {
            if(frq[1]) {
                cout<<"NO";
                return 0;
            }
            ++frq[1];
            continue;
        }else if(v[i]==n) {
            if(frq[n]) {
                cout<<"NO";
                return 0;
            }
            ++frq[n];
            continue;
        }
        if(frq[v[i]] && frq[v[i]+1]) {
            cout<<"NO";
            return 0;
        }
        else if(frq[v[i]]) ++frq[v[i]+1];
        else ++frq[v[i]];
    }
    cout<<"YES";
    return 0;
}
