#include <fstream>
#include <cstring>
#define DN 5000005
#define LL long long
using namespace std;

int n,cnt[260],v[DN],vnou[DN];

int main()
{
    ifstream f("algsort.in");
    ofstream g("algsort.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>v[i];
    for(int pc=0; pc<=56; pc+=7) {
        memset(cnt,0,sizeof(cnt));
        for(int i=1; i<=n; ++i) {
            int cc=(v[i]>>pc)&(0x0000007f);
            ++cnt[cc+1];
        }
        for(int j=1; j<=256; ++j) cnt[j]+=cnt[j-1];
        for(int i=1; i<=n; ++i) {
            int cc=(v[i]>>pc)&(0x0000007f);
            ++cnt[cc];
            vnou[cnt[cc]]=v[i];
        }
        memcpy(v,vnou,(n+1)*sizeof(int));
    }
    for(int i=1; i<=n; ++i) g<<v[i]<<' ';
    return 0;
}
