#include <iostream>
#include <stack>
#define x first
#define y second
#define LL long long
#define DN 20005
using namespace std;

typedef pair<LL, LL> per;
stack<per> q;

LL n,d;
LL v[DN],r,cst;

int main()
{
    cin>>n>>d;
    for(int i=1; i<=n; ++i) cin>>v[i];
    for(LL i=1; i<=n; ++i)
        if(v[i]==d) r+=d;
        else if(v[i]<d) {
            r+=v[i];
            q.push(make_pair(d-v[i],i));
        }else {
            //cout<<"v[i],i:"<<v[i]<<' '<<i<<endl;
            r+=d;
            LL rest=v[i]-d,rc=0,sv,tp;
            bool ok=0;
            for(;q.size() && rest>0;) {
                rc=0;
                ok=0;
                //cout<<q.top().x<<' '<<q.top().y<<'\n';
                if(rest>=q.top().x) rc+=q.top().x;
                else {
                    rc+=rest;
                    ok=1;
                    sv=q.top().x-rest;
                    tp=q.top().y;
                }
                rest-=q.top().x;
                cst+=(rc*(i-q.top().y)*1LL);
                r+=rc;
                q.pop();
                if(ok) q.push(make_pair(sv,tp));
            }
        }
    cout<<r<<' '<<cst;
    return 0;
}
