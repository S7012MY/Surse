#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#define DL 1000005
#define DN 10005
#define DA 26//dimensiunea alfabetului
using namespace std;

int lg,n,l,final[DN],ic,sc;
char tx[DL],c[DN];

struct ac {
    vector<int> nd;//sirurile care se termina in nodul curent
    int n0;//numarul de potriviri din nodul curent sau din fii lui
    ac *f[DA],*fail;
    ac() {
        n0=0;
        fail=NULL;
        memset(f,0,sizeof(f));
    }
} *q[DN*DN],*t,*p;


void ins(ac *t,char *p,int i) {//inserarea se face ca si la trie
    if(!isalpha(*p)) {
        t->nd.push_back(i);
        return;
    }
    int urm=*p-'a';
    if(0==t->f[urm]) t->f[urm]=new ac;
    ins(t->f[urm],p+1,i);
}

void bfs(ac *t) {
    ac *dolar;//unde o sa mearga fail-ul fiecarui nod
    t->fail=t;
    for(q[ic=sc=1]=t;ic<=sc;++ic) {
        ac *fr=q[ic];
        for(int i=0; i<DA; ++i) if(fr->f[i]!=NULL) {//nodul caruia ii cautam fail-ul
            //ne ducem in fail pana gasim un nod care are ca fiu ultima litera a nodului sau pana ajungem in radacina
            for(dolar=fr->fail;dolar!=t && dolar->f[i]==NULL;dolar=dolar->fail);

            if(dolar->f[i]!=NULL && dolar->f[i]!=fr->f[i]) dolar=dolar->f[i];
            fr->f[i]->fail=dolar;
            q[++sc]=fr->f[i];
        }
    }
    t->fail=NULL;
}


void antibfs(ac *t) {
    //parcurgem nodurile in ordinea inversa a bfs-ului astfel fiecare nod va fi parcurs dupa ce au
    //fost parcursi toti fii lui si astfel putem calcula n0
    for(int i=sc; i>0; --i) {
        ac *fr=q[i];
        if(fr->fail!=NULL) fr->fail->n0+=fr->n0;
        //parcurgem toate cuvintele care se termina in nodul curent si actualizam solutia
        for(int j=0; j<fr->nd.size(); ++j) final[fr->nd[j]]=fr->n0;
    }
}

int main()
{
    freopen("ahocorasick.in","r",stdin);
    freopen("ahocorasick.out","w",stdout);
    scanf("%s",tx);
    scanf("%d",&n);
    t=new ac;
    for(int i=1; i<=n; ++i) {
        scanf("%s",c);
        ins(t,c,i);
    }
    bfs(t);
    p=t;
    lg=strlen(tx);
    for(int i=0; i<lg; ++i) {
        int urm=tx[i]-'a';
        //cautam o muchie pe care sa putem merge in jos
        for(;p->f[urm]==NULL && p!=t;p=p->fail);
        if(p->f[urm]!=NULL) p=p->f[urm];
        ++p->n0;//creste numarul de potriviri din nodul curent
    }
    antibfs(t);
    for(int i=1; i<=n; ++i) printf("%d\n",final[i]);
    return 0;
}
