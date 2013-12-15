#include <cstdio>
#include <cstring>

char cod[105];

int add(char op, int p) {
    if(cod[p]==1) {
        if(op=='D') {
            cod[p]=4;
            return 1;
        }else if(op=='U') {
            cod[p]=4;
            if(p==0) return 0;
            return add(op,p-1);
        }else if(op=='L'){
            cod[p]=2;
            if(p==0) return 0;
            return add(op,p-1);
        }else {
            cod[p]=2;
            return 1;
        }
    }
    else if(cod[p]==2) {
        if(op=='D') {
            cod[p]=3;
            return 1;
        }else if(op=='U') {
            cod[p]=3;
            if(p==0) return 0;
            return add(op,p-1);
        }else if(op=='L'){
            cod[p]=1;
            return 1;
        }else {
            cod[p]=1;
            if(p==0) return 0;
            return add(op,p-1);
        }
    }
    else if(cod[p]==3) {
        if(op=='D') {
            cod[p]=2;
            if(p==0) return 0;
            return add(op,p-1);
        }else if(op=='U') {
            cod[p]=2;
            return 1;
        }else if(op=='L'){
            cod[p]=4;
            return 1;
        }else {
            cod[p]=4;
            if(p==0) return 0;
            return add(op,p-1);
        }
    }
    else {
        if(op=='D') {
            cod[p]=1;
            if(p==0) return 0;
            return add(op,p-1);
        }else if(op=='U') {
            cod[p]=1;
            return 1;
        }else if(op=='L'){
            cod[p]=3;
            if(p==0) return 0;
            return add(op,p-1);
        }else {
            cod[p]=3;
            return 1;
        }
    }
}

int main()
{
    freopen("codpatrat.in","r",stdin);
    freopen("codpatrat.out","w",stdout);
    scanf("%s\n",cod);
    int lg=strlen(cod)-1,cnt=0;
    for(int i=0; i<=lg; ++i) cod[i]-='0';
    char op;int nr;
    for(;!feof(stdin);) {
        scanf("%c %d\n",&op, &nr);
        //fprintf(stderr,"%c %d\n",op, nr);
        ++cnt;
        for(int i=1; i<=nr; ++i) {
            if(!add(op,lg)){
                printf("%d\n",cnt);
                return 0;
            }
            //for(int i=0; i<=lg; ++i) fprintf(stderr,"%d",cod[i]);
        }
    }
    for(int i=0; i<=lg; ++i) printf("%d",cod[i]);
    return 0;
}
