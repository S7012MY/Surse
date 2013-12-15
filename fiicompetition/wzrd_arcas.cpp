#include <cstdio>
#include <cstring>
#include <utility>
#define x first
#define y second
#define DN 250005
#define DM 1000000005
using namespace std;

typedef pair<int,int> per;

int n,m,ranks[DN * 2],rank,negru[3 * DN+1], gri[3 * DN+1], alb[3 * DN+1];

per cache[DN];
bool cached[DN];

per bagaMare(int start) {
    int targ=start >> 1;
    if(cached[targ])
        return cache[targ];

    if(rank == 1)
        cache[targ]=make_pair(1, 0);
    else if(rank <= n+1) {

        memset(negru, 0, sizeof(negru));
        memset(gri, 0, sizeof(gri));
        memset(alb, 0, sizeof(alb));
        gri[start >> 1]=1;
        for(int i=1; i<n * 2; i++) {
            int target=(i-1 +(i>start ? 1 : 0)) >> 1;
            if(ranks[i]<rank)
                negru[target]++;
            else
                alb[target]++;
        }

        int archer1, archer2;
        if(start<2) {
            archer1=ranks[1];
            archer2=rank;
        } else {
            archer1=ranks[1];
            archer2=ranks[2];
        }

        int s_negru=0, s_gri=0, s_alb=0;
        if(archer1<rank)
            s_negru++;
        else if(archer1 == rank)
            s_gri++;
        else
            s_alb++;
        if(archer2<rank)
            s_negru++;
        else if(archer2 == rank)
            s_gri++;
        else
            s_alb++;

        int cumulat_negru=0, cumulat_gri=0, cumulat_alb=0;
        int seen=-1;
        int bumps=0;

        for(int round=0; round<3 * n; round++) {
            if(round >= 2 * n &&(s_gri == 1)) {
                seen=round;
                break;
            }
            int loser;
            if(s_negru>0) {
                if(s_negru == 2)
                    loser=0;
                else if(s_gri == 1) {
                    loser=1;
                    bumps++;
                } else
                    loser=2;
            }
            else
                loser=2;
            int new_p=round+n;
            if(new_p <= 3 * n) {

                if(loser == 0) {
                    negru[new_p]++;
                    s_negru--;
                } else if(loser == 1) {
                    gri[new_p]++;
                    s_gri--;
                } else {
                    alb[new_p]++;
                    s_alb--;
                }
            }

            cumulat_negru += negru[round+1];
            cumulat_gri += gri[round+1];
            cumulat_alb += alb[round+1];

            if(cumulat_negru>0) {
                s_negru++;
                cumulat_negru--;
            }
            else if(cumulat_gri>0) {
                s_gri++;
                cumulat_gri--;
            } else {
                s_alb++;
                cumulat_alb--;
            }
        }

        if(m>seen)
            bumps++;

        cache[targ]=make_pair(n -((m-seen+n-1) % n), bumps);
    } else {
        int alb[n], gri[n];
        memset(alb, 0, sizeof(alb));
        memset(gri, 0, sizeof(gri));

        gri[start >> 1]=1;

        for(int i=1; i<2 * n; i++)
            if(ranks[i]>rank)
                alb[(i-1 +(i>start ? 1 : 0)) >> 1]++;
        int shift_alb=0, shift_gri=0;
        int bumps=0;
        for(int it=0; it<3; it++) {
            int pos=0;
            do {
                int cur_alb=alb[pos]+shift_alb;
                int cur_gri=gri[pos]+shift_gri;

                if(cur_alb+cur_gri>1) {
                    if(pos>0) {
                        alb[pos]=1;
                        shift_alb=cur_alb-1;
                        gri[pos]=0;
                        if(cur_gri>0)
                            shift_gri=cur_gri;
                        else
                            shift_gri=0;
                    } else {
                        if(cur_gri>0) {
                            gri[pos]=1;
                            alb[pos]=0;
                            shift_gri=cur_gri-1;
                            shift_alb=cur_alb;
                        }
                        else {
                            gri[pos]=0;
                            alb[pos]=1;
                            shift_gri=0;
                            shift_alb=cur_alb-1;
                        }
                    }
                }
                else {
                    if(pos>0) {
                        alb[pos]=cur_alb;
                        gri[pos]=cur_gri;
                        shift_alb=0;
                        shift_gri=0;
                    } else {
                        if(cur_gri>0)
                            bumps++;
                        alb[pos]=0;
                        gri[pos]=0;
                        shift_alb=cur_alb;
                        shift_gri=cur_gri;
                    }
                }
                if(pos == 0)
                    pos=n-1;
                else
                    pos--;
            } while(pos>0);
        }

        for(int i=0; i<n; i++)
            if(gri[i]>0) {
                cache[targ]=make_pair(i+1, bumps);
                break;
            }
    }

    cached[targ]=1;
    return cache[targ];
}

per search(int s, int e)
{
    per start, end, mid;
    int mi;
    start=bagaMare(s * 2-1);
    end=bagaMare(e * 2-1);
    while((e-s)>1) {
        mi=(s+e) >> 1;
        mid=bagaMare(mi * 2-1);

        if(start.x<mid.x) {
            e=mi;
            end=mid;
        } else {
            s=mi;
            start=mid;
        }
    }

    if(start.x<end.x)
        return make_pair(start.x, s);
    else
        return make_pair(end.x, e);
}

int main()
{
    freopen("arcas.in","r",stdin);
    freopen("arcas.out","w",stdout);
    scanf("%d %d",&n,&m);
    m=2*n+(m%n);
    for(int i=0; i<n * 2; i++) scanf("%d",&ranks[i]);

    rank=ranks[0];
    int best_start;
    per start, end, mid;
    int s=1, e=n, mi;
    start=bagaMare(s * 2-1);
    end=bagaMare(e * 2-1);
    if(start.y>end.y) {
        while((e-s)>1) {
            mi=(s+e) >> 1;
            mid=bagaMare(mi * 2-1);

            if(mid.y>end.y) {
                s=mi;
                start=mid;
            }
            else {
                e=mi;
                end=mid;
            }
        }

        if(start.y>end.y)
            mi=e;
        else
            mi=s;

        per start_side=search(1, mi-1);
        per end_side=search(mi, n);

        if(start_side.x<end_side.x)
            best_start=start_side.y;
        else
            best_start=end_side.y;
    }
    else {
        per best=search(1, n);
        best_start=best.y;
    }
    printf("%d",best_start);

    return 0;
}
