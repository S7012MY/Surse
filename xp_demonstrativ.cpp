//Se calculeaza sirul val pe bucati de lungime sqrt(N). Am luat valoaream maxima a sqrt(N) pt a nu face calcule in plus
//atunci cand dorim sa calculam prod[i] ne uitam in produsul val pana la bucata precedenta si la produsul din bucata urmatoare pana la n si parcurgem bucata curenta
//complexitate timp: sqrt(N)* sqrt(N)=N Memorie: sqrt(N)
#include <fstream>
#include <iostream>
#define SQ 3000
using namespace std;

#define A(Aprev, Bprev) (((Aprev + p - 1) ^ (Bprev + 1)) % p)
#define B(Aprev, Bprev) (((Aprev + p - 1) | (Bprev + 1)) % p)
#define VAL(Acurr, Bcurr, pos) (max(1,((((pos) % (p)) ^ (((Acurr + 1) & (Bcurr + 1)) % (p))) % (p))))

int p1[SQ+10], p2[SQ+10], v1[SQ+10], v2[SQ+10], v3[SQ+10],n,a,b,c,d,p,q,val,poz,x,y,aux;
long long rez;

//p1 = produsul pe o bucata de lungime SQ
//p2 = produsul la dreapta pana la n

int main()
{
    ifstream f("xp.in");
    ofstream g("xp.out");
    f>>n>>a>>b>>p>>q;
    x=a;y=b;
    poz=1;
    val=VAL(a,b,1);
    p1[1]=val;
    for(int i=2; i<=n; ++i) {
        if(1==i%SQ) {//incep o bucata noua
            ++poz;
            p1[poz]=1;
        }
        c=A(a,b);
        d=B(a,b);
        a=c; b=d;
        val=VAL(a,b,i);
        p1[poz]=(p1[poz]*1LL*val)%q;
    }
    p2[poz+1]=1;
    for(int i=poz; 0<i; --i) p2[i]=(p2[i+1]*1LL*p1[i])%q;//caluclez produsul la dreapta
    a=x;b=y; aux=1; p1[0]=1;
    int i=1,l;
    for(int j=1; j<=poz; ++j) {//parcurg pucatile in ordine
        l=min(n-i+1,SQ);
        aux=(aux*1LL*p1[j-1])%q;//produsul din bucatile precedente
        for(int w=1; w<=SQ && i<=n; ++i) {
            v1[w++]=VAL(a,b,i);//sirul val pe fiecare pozitie din bucata
            c=A(a,b);
            d=B(a,b);
            a=c; b=d;
        }
        v2[0]=v3[l+1]=1;
        for(int t=1; t<=l; ++t) v2[t]=(v2[t-1]*1LL*v1[t])%q;//produsul valorilor din bucata de lungime sqrt la stanga
        for(int t=l; 0<t; --t) v3[t]=(v3[t+1]*1LL*v1[t])%q;//produsul valorilor din bucata de lungime sqrt la dreapta
        for(int t=1; t<=l; ++t) {//calculez rezultatul in bucata curenta
            int act=(aux*1LL*p2[j+1])%q;//prod
	    act=(act*1LL*v2[t-1])%q;
	    act=(act*1LL*v3[t+1])%q;
	    rez^=act;
        }
    }
    g<<rez;
   // cout<<rez;
    return 0;
}

