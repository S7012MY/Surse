#include <fstream>
#include <cstring>
#define DN 10000001
//X[ k ] = (A * X[k - 1] + B) % NRI[ k ] + 1;
using namespace std;

int urm[DN*10],st[DN],viz[DN];
char txt[DN*10];

int find(int x) {
    int a=x,b;
    for(;0==viz[a];a=urm[a+1]);
    for(;0==viz[x] && a;) {
        b=urm[x+1];
        urm[x]=a;
        x=b;
    }
    if(0==a) return -1;
    return a;
}

inline int ok(char x) {
        return x=='I' || x=='E' || x=='Q';
}

int main()
{
    int a,b,ult=0,nr=0,vf=0;
    long long sum=0;
    ifstream f("jstc.in");
    ofstream g("jstc.out");
    f>>a>>b;
    f.get();
    f.get(txt,DN*10);
    int sz=strlen(txt);
    for(int i=1; i<=sz; ++i) urm[i]=sz+1;
    urm[sz+1]=sz+1;
    for(int i=0; ok(txt[i]); ++i) {
        if('I'==txt[i]) {
            ++nr;
            st[++vf]=nr;
            viz[nr]=1;
            urm[nr]=nr;
        }else if('E'==txt[i]) {
            viz[st[vf]]=0;
            --vf;
        }else {
            ult=(a*1LL*ult+b)%nr+1;
            if(st[vf]<ult) {
                --sum; continue;
            }
            sum+=1LL*find(ult);
        }
    }
    g<<sum;
    return 0;
}

