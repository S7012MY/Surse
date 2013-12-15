#include <cstdio>
#define NMAX 10100

char A[NMAX], B[NMAX];
int pi[NMAX];
int N,M,pozA,pozB,nextpozB,left,right;

int main() {
    freopen("potrivire.in", "r", stdin);
    freopen("potrivire.out", "w", stdout);
    scanf("%d %d",&N,&M);
    scanf("%s %s",A+1,B+1);
    right=pozB=0;
    int i,k;
    for (;pozB+1<=M && B[pozB + 1]=='*';++pozB);
    if (pozB==M) {
        printf("1 1\n");
        return 0;
    }
    left=0;
    for(;1;) {
        for(;pozB+1<=M && B[pozB + 1]=='*';++pozB);
        if (pozB == M) break;
        nextpozB=pozB+1;
        pi[nextpozB]=k=nextpozB - 1;
        for(;nextpozB + 1<=M && B[nextpozB + 1] != '*';) {
            nextpozB++;
            for (;k>pozB && B[k+1]!=B[nextpozB];k=pi[k]);
            if (B[k + 1] == B[nextpozB])
                ++k;
            pi[nextpozB]=k;
        }
        k=pozB;
        for (i=right+1; i<=N; ++i) {
            for (;k>pozB && B[k+1]!=A[i];k=pi[k]);
            if (B[k+1]==A[i]) ++k;
            if (k==nextpozB) {
                if(!right) left=i-(nextpozB-pozB)+1;
                right=i;
                break;
            }
        }
        if (i>N) break;
        pozB=nextpozB;
    }

    if(pozB<M) printf("-1\n");
    else printf("%d %d\n", left, right);
    return 0;
}
