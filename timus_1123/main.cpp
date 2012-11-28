#include <cstdio>
#include <cstring>

typedef int huge[2005];
char s[2005];
huge nr;

void inc(huge nr,int p) {
    ++nr[p];
    int i;
    for(i=p;nr[i]>9;nr[i]%=10,++nr[i+1],++i);
}

void printh(huge nr) {
    for(int i=nr[0]; i>0; --i) printf("%d",nr[i]);
    printf("\n");
}

bool ispal(huge nr) {
    int m=nr[0]/2;
    for(int i=1; i<=m; ++i) if(nr[i]!=nr[nr[0]-i+1]) return 0;
    return 1;
}

int main()
{
    scanf("%s",s);
    nr[0]=strlen(s);
    for(int i=0; i<nr[0]; ++i) nr[nr[0]-i]=s[i]-'0';
    int m=nr[0]/2;
    for(int i=1; i<=m; ++i) if(nr[i]!=nr[nr[0]-i+1]) {
        int ok=0;
        if(nr[i]>nr[nr[0]-i+1])ok=1;
        nr[i]=nr[nr[0]-i+1];
        if(ok)inc(nr,i+1);
        //printh(nr);
    }
    for(int i=m+1; i<=nr[0]; ++i) if(nr[i]!=nr[nr[0]-i+1]) nr[nr[0]-i+1]=nr[i];
    printh(nr);
    return 0;
}
