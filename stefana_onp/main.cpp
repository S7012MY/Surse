#include <cstdio>
#include <cstring>
#include <cctype>
#define BM 405
int t, n,dims,dimo;
char semn[BM],out[BM],sc[BM];
int prior(char c){
    if(isalpha(c))return 0;
    if(c=='+'||c=='-')return 1;
    if(c=='*'||c=='/')return 2;
    if(c=='^')return 3;
    return 4;
}
void frumos(){
    int i;
    for(i=0;i<n;++i){
       if(prior(sc[i])==0)out[++dimo]=sc[i];
       else if(prior(sc[i])>0&&prior(sc[i])<4){
            for(;dims&&prior(semn[dims])<4&&prior(semn[dims])>=prior(sc[i]);){
                out[++dimo]=semn[dims];
                --dims;
            }
            semn[++dims]=sc[i];
       }
      else if(sc[i]=='(')semn[++dims]=sc[i];
      else if(sc[i]==')'){
           for(;dims&&semn[dims]!='(';){
                out[++dimo]=semn[dims];
                --dims;
            }
            --dims;
       }
    }
     for(;dims;){
        out[++dimo]=semn[dims];
        --dims;
    }
}
int main () {
    scanf("%d",&t);
    for(;t;--t){
        scanf("%s",sc);
        dimo=0;
        dims=0;
        n=strlen(sc);
        frumos();
        out[dimo+2]=0;
        for(int i=1;i<=dimo;++i)printf("%c",out[i]);
        printf("\n");
    }
    return 0;
}
