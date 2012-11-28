#include <iostream>
#include <algorithm>
#define DN  1005
#define x first
#define y second
using namespace std;

int n,s;
pair<int,int> d[DN];

int main()
{
    cin>>s>>n;
    for(int i=1; i<=n; ++i) cin>>d[i].x>>d[i].y;
    sort(d+1,d+n+1);
    for(int i=1; i<=n; ++i) {
        if(s<=d[i].x) {
            cout<<"NO";
            return 0;
        }
        s+=d[i].y;
    }
    cout<<"YES";
    return 0;
}
