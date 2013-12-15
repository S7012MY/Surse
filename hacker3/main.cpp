#include <iostream>
#include <fstream>
#include <vector>
#define x first
#define y second
#define DN 50005
using namespace std;

typedef pair<int,int> per;
vector<per> a;
int n;
long long bst;

int main()
{
    ifstream f("hacker3.in");
    ofstream g("hacker3.out");
    f>>n;
    if(n<=10000) {
        for(int i=1; i<=n; ++i) {
            int q,p;
            f>>q>>p;
            a.push_back(make_pair(q,p));
        }
        a.push_back(make_pair(0,0));
        for(int i=n-1; i>=0; --i) {
           // cout<<a[i].x<<' '<<a[i].y<<'\n';
            bst=min(bst*2+a[i].x,bst+a[i].y);
        }
    }
    else {
        //int cs=n-10000,cd=n;
        f.close();
        for(int cs=max(n-10000,1),cd=n;cs>0; cd=cs-1,cs=max(1,cs-10000)) {
            f.open("hacker3.in");
            f>>n;
            for(int i=1; i<=n; ++i) {
                int q,p;
                f>>q>>p;
               // cout<<q<<' '<<p<<'\n';
                if(i>=cs && i<=cd) a.push_back(make_pair(q,p));
            }
            a.push_back(make_pair(0,0));
            for(int i=a.size()-1; i>=0; --i) {
               // cout<<a[i].x<<' '<<a[i].y<<'\n';
                bst=min(bst*2+a[i].x,bst+a[i].y);
            }
            f.close();
            a.clear();
            if(cs==1) break;
        }
    }
    g<<bst;
    //cout<<sizeof(a)/1024;
    return 0;
}
