#include <cstdio>
#include <set>
using namespace std;

char zzz[10];
double nr,rez;
int cant;
multiset<double, greater<double> >s;
typedef multiset<double, greater<double> >::iterator is;

int main()
{
    for(;;) {
        scanf("%s",zzz);
        if(zzz[0]=='Q') break;
        else if(zzz[0]=='B') {
            scanf("%lf",&nr);
            s.insert(nr);
        }
        else if(zzz[0]=='D') {
            scanf("%lf",&nr);
            s.erase(s.find(nr));
        }
        else if(zzz[0]=='S') {
            scanf("%lf %d",&nr,&cant);
            int z=1;
            for(is i=s.begin();
            (*i)>=nr &&
            i!=s.end() && z<=cant; ++z,++i) rez+=0.01;
        }

    }
    printf("%.2lf",rez);
    return 0;
}
