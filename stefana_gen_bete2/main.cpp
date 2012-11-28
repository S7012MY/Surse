#include <cstdio>
#include <algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

int f[1000005];
int main () {
    int n,i,el;
    freopen("bete2.in","w",stdout);
    srand(time(NULL));
    n=rand()%2997+3;
    printf("%d ",n);
    for(i=1;i<=n;){
        el=rand()%1000000+1;
        if(f[el]==0){
            printf("%d ",el);
            f[el]=1;
            ++i;
        }

    }
}
