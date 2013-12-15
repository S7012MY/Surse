#include <cstdio>
#include <cstring>
#define DN 1005//numarul maxim de cuvinte
#define DL 55//lungimea maxima

char sirCurent[DL],r[DN][DL];//sirurile de afisat
int n,m,dim,lc;//lungime curenta

void afisLinie() {
    if(dim==1) printf("%s",r[1]);
    else {
        int ns=(m-lc)/(dim-1),ms=(m-lc)%(dim-1);
        printf("%s",r[1]);
        for(int i=1; i<dim; ++i) {
            for(int j=1; j<=ns; ++j) printf(" ");
            if(i<=ms) printf(" ");
            printf("%s",r[i+1]);
        }
    }
    printf("\n");
}

int main()
{
    freopen("paginatie.in","r",stdin);
    freopen("paginatie.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    //citesc primul cuvant
    fgets(sirCurent,DL,stdin);
    sirCurent[strlen(sirCurent)-1]=0;//elimin caracterul newline de la sf cuvantului
    int x=1,y;//x=nr de linii, y=lungimea totala a liniei
    y=strlen(sirCurent);
    strcpy(r[1],sirCurent);
    dim=1; lc=y;
    for(;fgets(sirCurent,DL,stdin)!=NULL;) {//mai pot citit cuvinte din fisier
        sirCurent[strlen(sirCurent)-1]=0;//elimin caracterul newline de la sf cuvantului
        if(y+strlen(sirCurent)+1>m) {
            afisLinie();
            ++x;
            if(x>n) {
                printf("\n");
                x=1;
            }
            dim=1;
            strcpy(r[dim],sirCurent);
            y=lc=strlen(sirCurent);
        }else {
            strcpy(r[++dim],sirCurent);
            int ls=strlen(sirCurent);
            y+=ls+1; lc+=ls;
        }
    }
    afisLinie();
    return 0;
}
