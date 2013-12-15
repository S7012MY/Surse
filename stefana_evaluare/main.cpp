#include <cstdio>
#include <cstring>
#define BM 100005
#define MARE 1000000000
int out[BM],n,dimo,dims,rez[BM],dimr;
char semn[BM],sc[BM];
int prior(char c){
    if(c=='+'||c=='-')return 1;
    if(c=='*'||c=='/') return 2;
    if(c>='0'&&c<='9') return 3;
    return 4;
}
int cacat(char c){
    if(c=='+')return MARE+1;
    if(c=='-')return MARE+2;
    if(c=='*')return MARE+3;
    if(c=='/')return MARE+4;
}
void frumos(){
    int i,nrc;
    for(i=0;i<n;++i){
        nrc=0;
        if(prior(sc[i])==3){
            for(;prior(sc[i])==3;++i){
                nrc=nrc*10+sc[i]-'0';
            }
        out[++dimo]=nrc;
        --i;
        }
        else if(prior(sc[i])==1||prior(sc[i])==2){
            for(;dims&&prior(semn[dims])<4&&prior(semn[dims])>=prior(sc[i]);){
                out[++dimo]=cacat(semn[dims]);
                --dims;
            }
            semn[++dims]=sc[i];
        }
        else if(sc[i]=='(')semn[++dims]='(';
        else if (sc[i]==')'){
            for(;dims&&semn[dims]!='(';--dims)out[++dimo]=cacat(semn[dims]);
            --dims;
        }
    }
      for(;dims;--dims)out[++dimo]=cacat(semn[dims]);
}
int eval(){
    int i;
    for(i=1;i<=dimo;++i){
        if(out[i]<=MARE)rez[++dimr]=out[i];
        else if(out[i]==MARE+1)rez[dimr-1]+=rez[dimr],--dimr;
        else if(out[i]==MARE+2)rez[dimr-1]-=rez[dimr],--dimr;
        else if(out[i]==MARE+3)rez[dimr-1]*=rez[dimr],--dimr;
        else if(out[i]==MARE+4)rez[dimr-1]/=rez[dimr],--dimr;
    }
    return rez[1];
}
int main (){
    int i;
    freopen("evaluare.in","r",stdin);
    freopen("evaluare.out","w",stdout);
    scanf("%s",sc);
    n=strlen(sc);
    frumos();
   // for(i=1;i<=dimo;++i)fprintf(stderr,"%d ",out[i]);
    printf("%d",eval());
}
