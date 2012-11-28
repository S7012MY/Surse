#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

unsigned n,i,rez,x;
priority_queue<unsigned,vector<unsigned>, greater<int> > c;

int main()
{
    cin>>n;
    for(i=1; i<=n/2+1; ++i) {
        cin>>x;
        c.push(x);
    }
    for(;i<=n; ++i) {
        cin>>x;
        c.push(x);
        c.pop();
    }
    int lim=n/2;
    if(n%2==0) ++lim;
    for(;c.size()>lim;c.pop());
    rez=c.top();
    if(n%2==0) {
        c.pop();
        rez+=c.top();
        cout<<fixed<<setprecision(1)<<rez*0.5;
        return 0;
    }
    cout<<rez;
    return 0;
}
