#include <fstream>
#define DT 200001
#define DN 300005
using namespace std;

int n,a[DN],b[DN],viz[DN],d[2];

int main()
{
    ifstream f("meneaito.in");
    ofstream g("meneaito.out");
    f>>n;
    for(int i=2; i<n; ++i) f>>a[i];
    for(int i=2; i<n; ++i) f>>b[i];
    for(int i=2; i<n; ++i) {
        if(a[i]==i && b[i]==i) {
            g<<-1;
            return 0;
        }
        if(a[i]>i || b[i]<i) continue;
        int tc=0,fail=0,s=0;
        d[0]=i-a[i]; d[1]=b[i]-i;
        for(;tc<DT;) {
            tc+=d[s];
            if(viz[tc]) ++fail;
            else fail=0;
            viz[tc]=1;
            s^=1;
            tc+=d[s];
            if(fail>200) break;
        }
    }
    for(int i=0; i<DT; ++i) if(!viz[i]) {
        g<<i;
        return 0;
    }
    g<<-1;
    return 0;
}
