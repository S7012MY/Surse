#include <iostream>
#include <fstream>
#define DN 1005
using namespace std;

/*
    Piept pui congelator, tai ceapa, pus ulei in cratita + ceapa + piept pui cubulete + lingura mare
    gogsar tocat din frigider + piper + putina apa clocotita
    foc mic + amestecat 20 min

    orez fiert in apa cu sare  linguri orez
    sau luat cratita mare pus si orezul inauntru

*/

int n,s,sir[DN],rez;

unsigned int v[1200005];

inline unsigned int hashKey(unsigned int value) {
    return value & 0x000fffff;
}

inline unsigned int partialValue(unsigned int value) {
    return value >> 20;
}

inline unsigned int getVal(unsigned int map) {
    return map & 0x000003ff;
}

inline unsigned int getCnt(unsigned int map) {
    return map >> 10;
}

inline void insert(unsigned int value) {
    unsigned int key = hashKey(value);
    for(; v[key] != 0 && getVal(v[key]) != partialValue(value); ++key);
    v[key] |= partialValue(value);
    v[key] += 1u << 10;
}

inline unsigned int count(unsigned int value) {
    unsigned int key = hashKey(value);
    for(; v[key] != 0 && getVal(v[key]) != partialValue(value); ++key);
    //cout << key << ' ' << getCnt(v[key]) << '\n';
    return getCnt(v[key]);
}

int main()
{
    ifstream f("take5.in");
    ofstream g("take5.out");
    f>>n>>s;
    for(int i=1; i<=n; ++i) f>>sir[i];
    for(int c=3; c<n-1; ++c) {
        int b=c-1;
        for(int a=1; a<b; ++a) if(sir[a]+sir[b]<=s){
            insert(sir[a]+sir[b]);
        }
        s-=sir[c];
        for(int d=c+1; d<n; ++d) {
            s-=sir[d];
            for(int e=d+1; e<=n; ++e) {
                if(s-sir[e]>=0 && s-sir[e]<=800000000) rez+=count(s-sir[e]);
            }
            s+=sir[d];
        }
        s+=sir[c];
    }
    g<<rez;
    return 0;
}
