#include <cstdio>
#include <set>
#include <map>
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
typedef set<per>::iterator is;

set<per> s;
map<int, int> mp;//bloc,timp
int a,b;
char op;

int main()
{
    for(int i=1; i<=30000; ++i) {
        s.insert(make_pair(0,i));
        mp[i]=0;
    }
    for(;scanf("%d %c",&a,&op)!=-1;) {
        if('+'==op) {
            is poz=s.begin();
            printf("%d\n",poz->y);
            mp[poz->y]=poz->x+600-1;
            s.insert(make_pair(poz->x+600,poz->y));
            s.erase(poz);
        }else {
            scanf("%d",&b);
            if(mp[b]>=a) {
                printf("+\n");
                s.erase(make_pair(mp[b],b));
                mp[b]+=600-1;
                s.insert(make_pair(mp[b],b));
            }else printf("-\n");
        }
    }
    return 0;
}
