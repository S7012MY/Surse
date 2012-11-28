#include <iostream>
#include <stack>
#include <cstdio>
#define x first
#define y second
#define mp make_pair
#define DN 1005
using namespace std;

typedef pair<int,int> per;
int n,m,k,v[DN];
stack<per> s;

int main()
{
    //freopen("input.in","r",stdin);
    //freopen("output","w",stdout);
    for(cin>>k; k;--k) {
        cin>>n>>m;
        int rez=0;
        for(int i=1; i<=m; ++i) v[i]=0;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                char x='9';
                while(x!='R' && x!='F') cin>>x;
                if(x=='F') ++v[j];
                else v[j]=0;
            }
            v[m+1]=0;
            s.push(make_pair(0,1));
            for(int j=1; j<=m+1; ++j) {
                rez=max(rez,v[j]);
                int lst=j;
                for(;s.size() && s.top().x>=v[j]; s.pop()) {
                    rez=max(rez,s.top().x*(j-s.top().y));
                    lst=s.top().y;
                }
                s.push(make_pair(v[j],lst));;
            }
        }
        cout<<rez*3<<'\n';
    }
    return 0;
}
