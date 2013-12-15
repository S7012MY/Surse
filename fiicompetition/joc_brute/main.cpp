#include <fstream>
#include <iostream>
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
#define DN 20005
#define DV 105
#define MULT (1<<30)
using namespace std;

int n,d[DN],p[DN],rez=MULT;

inline int count(int i) {
	return i?1+count(i&(i-1)):0;
}

int main()
{
    ifstream f("joc.in");
    ifstream g("joc.out");
    f>>n;
    for(int i=0; i<n; ++i) f>>d[i]>>p[i];
    for(unsigned int i=0; i<(1<<n); ++i) {
        if(count(i)<=rez) continue;
        int vc=100,cnt=0,ok=1;
        for(int j=0; j<n; ++j)
            if(i&(1<<j)) {
                ++cnt;
                vc=min(100,vc+d[j]);
            }else {
                if(min(vc+d[j],100)-p[j]<=0) {
                    ok=0;
                    break;
                }
                vc=min(100,min(vc+d[j],100)-p[j]);
            }
            if(ok) rez=min(rez,cnt);
    }
    int rc;
    g>>rc;
    if(rc!=rez) {
        cout<<rc<<' '<<rez<<"gresit";
        cout.flush();
        while(1);
    }else cout<<"Ok";
    return 0;
}
