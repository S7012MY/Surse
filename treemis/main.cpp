#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("treemis.in");
ofstream g("treemis.out");

#define DN 100005
#define ll long long
#define inf (1<<30)

int n, a[DN], viz[DN], secv[DN], P[DN], U[DN], t[DN];
int cresc[DN], desc[DN], f1Cresc[DN], f2Cresc[DN], f1Desc[DN], f2Desc[DN], aint[DN*4];
int cuEl[DN];
pair<int, int> v[DN];
vector<int> gf[DN];
int pEuler[DN], euler[DN*3], nivel[DN], aintE[DN*4*2];
int Rez=0;


void citeste(){
    f>>n;
    for(int i=1; i<=n; ++i){
        f>>a[i]; v[i]=make_pair(a[i], i);
    }

    int x, y;
    for(int i=1; i<n; ++i){
        f>>x>>y; ++x; ++y;
        gf[x].push_back(y);
        gf[y].push_back(x);
    }
}

void dfs(int nod){
    viz[nod]=1;
    secv[++secv[0]]=nod;
    P[nod]=secv[0];
    euler[++euler[0]]=nod;
    pEuler[nod]=euler[0];
    for(int i=0; i<(int)gf[nod].size(); ++i){
        int vc=gf[nod][i];
        if (viz[vc] == 0){
            t[vc]=nod;
            nivel[vc]=nivel[nod] + 1;
            dfs(vc);
            euler[ ++euler[0] ]=nod;
        }
    }
    U[nod]=secv[0];
}

void query(int nod, int st, int dr, int a, int b, int &Max, int &Cine, int tip){
    if (a <= st && dr <= b){
        if (tip == 1){// cresc e la putere
            if (Max < cresc[ aint[nod] ]){
                Max=cresc[ aint[nod] ];
                Cine=aint[nod];
            }
        }else{// e desc
            if (Max < desc[ aint[nod] ]){
                Max=desc[ aint[nod] ];
                Cine=aint[nod];
            }
        }

        return;
    }else{
        int mij=(st + dr) / 2;
        if (a <= mij) query(nod*2, st, mij, a, b, Max, Cine, tip);
        if (b > mij) query(nod*2+1, mij+1, dr, a, b, Max, Cine, tip);
    }
}

void update(int nod, int st, int dr, int poz, int val, int tip){
    if (st == dr){
        aint[nod]=val;
        return;
    }else{
        int mij=(st + dr) / 2;
        if (poz <= mij) update(nod*2, st, mij, poz, val, tip);
                   else update(nod*2+1, mij+1, dr, poz, val, tip);
        aint[nod]=aint[nod*2];
        if (tip == 1){
            if ( cresc[ aint[nod] ] < cresc[ aint[nod*2+1] ]){
                aint[nod]=aint[nod*2+1];
            }
        }else{
            if ( desc[ aint[nod] ] < desc[ aint[nod*2+1] ]){
                aint[nod]=aint[nod*2+1];
            }
        }
    }
}

void din1(){
    for(int i=0; i<=4*n; ++i) aint[i]=0;

    for(int i=n; i>=1; --i){
        int nod=v[i].second;
        int Max=0; int Cine=0;
        query(1, 1, n, P[nod], U[nod], Max, Cine, 1);
        cresc[nod]=1 + Max;
        f1Cresc[nod]=Cine;
        int inainte=cresc[ Cine ]; cresc[ Cine]=0;
        update(1, 1, n, P[Cine], Cine, 1);
        Max=0; int Cine2=0;
        query(1, 1, n, P[nod], U[nod], Max, Cine2, 1);
        f2Cresc[nod]=Cine2;
        cresc[Cine]=inainte;
        update(1, 1, n, P[Cine], Cine, 1);

        update(1, 1, n, P[nod], nod, 1);
    }
}

void din2(){
    for(int i=0; i<=4*n; ++i) aint[i]=0;

    for(int i=1; i<=n; ++i){
        int nod=v[i].second;
        int Max=0; int Cine=0;
        query(1, 1, n, P[nod], U[nod], Max, Cine, 2);
        desc[nod]=1 + Max;
        f1Desc[nod]=Cine;

        int inainte=desc[ Cine ]; desc[ Cine]=0;
        update(1, 1, n, P[Cine], Cine, 2);
        Max=0; int Cine2=0;
        query(1, 1, n, P[nod], U[nod], Max, Cine2, 2);
        f2Desc[nod]=Cine2;
        desc[Cine]=inainte;
        update(1, 1, n, P[Cine], Cine, 2);

        update(1, 1, n, P[nod], nod, 2);
    }
}

void query2(int nod, int st, int dr, int a, int b, int &Min, int &lca){
    if (a <= st && dr <= b){
        if ( nivel[ aintE[nod] ] < Min ){
            Min=nivel[  aintE[nod] ];
            lca=aintE[nod];
        }
        return;
    }else{
        int mij=(st + dr) / 2;
        if (a <= mij) query2(nod*2, st, mij, a, b, Min, lca);
        if (b > mij) query2(nod*2+1, mij+1, dr, a, b, Min, lca);
    }
}

int Lca(int x, int y){
    if (pEuler[x] > pEuler[y]) swap(x, y);
    int lca=0; int Min=inf;
    query2(1, 1, euler[0], pEuler[x], pEuler[y], Min, lca);
    return lca;
}

void fa(int nod, int st, int dr){
    if (st == dr){
        aintE[nod]=euler[st];
        return;
    }else{
        int mij=(st + dr) / 2;
        fa(nod*2, st, mij);
        fa(nod*2+1, mij+1, dr);
        aintE[nod]=aintE[nod*2];
        if (nivel[ aintE[nod] ] > nivel[ aintE[nod*2+1] ]){
            aintE[nod]=aintE[nod*2+1];
        }
    }
}

void uneste1(){
    fa(1, 1, euler[0]);

    for(int i=0; i<=n*4; ++i) aint[i] = 0;

    for(int i=1; i<=n; ++i){
        int nod = v[i].second;
        int fiu = f1Cresc[nod];
        int F = 0;
        for(int j=0; j<(int)gf[nod].size(); ++j){
            int vc = gf[nod][j];
            if (t[vc] == nod){
                if ( Lca(vc, fiu) == vc ){
                    F = vc; break;
                }
            }
        }
        if (F == 0) continue;
        int Max = 0; int Cine = 0;
        if (P[nod] <= P[F] - 1) query(1, 1, n, P[nod] , P[F]-1, Max, Cine, 2);
        Rez = max(Rez, Max + cresc[nod]);

        update(1, 1, n, P[nod], nod, 2);
    }

    for(int i=0; i<=n*4; ++i) aint[i] = 0;

    for(int i=n; i>=1; --i){
        int nod = v[i].second;
        int fiu = f1Desc[nod];
        int F = 0;
        for(int j=0; j<(int)gf[nod].size(); ++j){
            int vc = gf[nod][j];
            if (t[vc] == nod){
                if ( Lca(vc, fiu) == vc ){
                    F = vc; break;
                }
            }
        }
        if (F == 0) continue;
        int Max = 0; int Cine = 0;
        if (U[F] + 1 <= U[nod] ) query(1, 1, n, U[F] + 1, U[nod], Max, Cine, 1);
        Rez = max(Rez, Max + desc[nod]);

        update(1, 1, n, P[nod], nod, 1);
    }
}

void uneste2(){
    for(int i=0; i<=n*4; ++i) aint[i] = 0;

    for(int i=1; i<=n; ++i){
        int nod = v[i].second;
        int Max = -1; int Cine = -1;
        if (P[ t[nod] ] + 1 <= P[nod] - 1) query(1, 1, n, P[ t[nod] ]+1, P[nod]-1, Max, Cine, 2);
        //if (U[nod] + 1 <= U[ t[nod] ]) query(1, 1, n, U[nod]+1, U[ t[nod] ], Max, Cine, 2);
        update(1, 1, n, P[nod], nod, 2);
        Rez = max(Rez, cresc[nod] + Max);
    }

    for(int i=0; i<=n*4; ++i) aint[i] = 0;

    for(int i=n; i>=1; --i){
        int nod = v[i].second;
        int Max = -1; int Cine = -1;
        //if (P[ t[nod] ] + 1 <= P[nod] - 1) query(1, 1, n, P[ t[nod] ]+1, P[nod]-1, Max, Cine, 1);
        if (U[nod] + 1 <= U[ t[nod] ]) query(1, 1, n, U[nod]+1, U[ t[nod] ], Max, Cine, 1);
        update(1, 1, n, P[nod], nod, 1);
        Rez = max(Rez, desc[nod] + Max);
    }
}

void rezolva(){
    dfs(1);
    sort(v+1, v+n+1);
    din1();
    din2();
    uneste1();
    uneste2();
    g << Rez << "\n";
}


int main(){
    citeste();
    rezolva();

    f.close();
    g.close();

    return 0;
}
