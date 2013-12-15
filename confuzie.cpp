#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, n) REP(i, 1, n)
#define FOREACH(it, G) for(__typeof(G.begin()) it = G.begin() ; it != G.end() ; ++ it)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define read(n) int (n); scanf("%d", &(n))
#define read2(n, m) int (n), (m); scanf("%d %d", &(n), &(m))
#define read3(n, m, k) int (n), (m), (k); scanf("%d %d %d", &(n), &(m), &(k))
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

vector <int> G[160000], GT[160000], DG[160000];
bool vis[160000];
int stk[160000];

void dfs1(int nod) {
    vis[nod] = 1;
    FOREACH(it, GT[nod])
        if (!vis[*it])
            dfs1(*it);
    stk[++stk[0]] = nod;
}

vector <int> scc[160000];
int which[160000];

void dfs2(int nod, int tmp) {
    scc[tmp].pb(nod);
    vis[nod] = 1;
    which[nod] = tmp;
    FOREACH(it, G[nod])
        if (!vis[*it])
            dfs2(*it, tmp);
        else
            if (tmp != which[*it])
                DG[tmp].pb(which[*it]);
}

int sccCnt = 0;

void makeDag(int n) {
    FOR(i, n)
        if (!vis[i])
            dfs1(i);
    FOR(i, n)
        vis[i] = 0;
    int tmp = 0;
    REPD(i, stk[0], 1)
        if (!vis[stk[i]]) {
            ++tmp;
            dfs2(stk[i], tmp);
        }
    sccCnt = tmp;
    FOR(i, sccCnt) {
        vector <int> :: iterator it;
        it = unique (DG[i].begin(), DG[i].end());
        DG[i].resize(distance(DG[i].begin(), it));
    }
}

int dst[160000];

void dfs3(int nod) {
    vis[nod] = 1;
    FOREACH(it, DG[nod])
        if (!vis[*it])
            dfs3(*it);
    FOREACH(it, DG[nod])
        chmax(dst[nod], dst[*it] + 1);
}

void maxDist(int n) {
    FOR(i, n)
        vis[i] = 0;
    FOR(i, n)
        if (!vis[i])
            dfs3(i);
}

int pred[160000];
vector <int> L[160000], sol;

void solve(int n) {
    int lmax = 0, cnt = 0;
    FOR(i, n)
        FOREACH(it, DG[i])
            ++pred[*it];
    FOR(i, n) {
        vis[i] = 0;
        chmax(lmax, dst[i]);
        L[dst[i]].pb(i);
    }
    FOR(i, n)
        if (pred[i] == 0)
            ++cnt;
    for (; lmax >= 0; --lmax) {
        if (cnt == 1 && L[lmax].size() == 1)
            sol.pb(L[lmax][0]);
        FOREACH(it, L[lmax])
            FOREACH(nod, DG[*it])
                if (!vis[*nod]) {
                    --pred[*nod];
                    if (pred[*nod] == 0) {
                        vis[*nod] = 1;
                        ++cnt;
                    }
                }
        cnt -= L[lmax].size();
    }
}

vector <int> sortedSol;

void printData() {
    int sum = 0;
    FOREACH(it, sol)
        sum += scc[*it].size();
    printf("%d\n", sum);
    FOREACH(it, sol)
        FOREACH(it2, scc[*it])
            sortedSol.pb(*it2);
    sort(sortedSol.begin(), sortedSol.end());
    FOREACH(it, sortedSol)
        printf("%d ", *it);
}

int main() {
    freopen("drumuri5.in", "r", stdin);
    freopen("drumuri5.out", "w", stdout);

    read2(n, m);
    FOR(i, m) {
        read2(X0, Y0);
        G[X0].pb(Y0);
        GT[Y0].pb(X0);
    }

    makeDag(n);
    maxDist(sccCnt);
    solve(sccCnt);
    printData();

    return 0;
}
