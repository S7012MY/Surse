#include <cstdio>
#include <tr1/unordered_set>
using namespace std;
using namespace tr1;

unordered_set<int> s;

int main()
{
    int n,i,op,p;
    freopen("hashuri.in","r",stdin);
    freopen("hashuri.out","w",stdout);
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d %d",&op,&p);
        if(op==1) s.insert(p);
        else if(op==2) s.erase(p);
        else {
            if(s.find(p)!=s.end()) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
