#include <cstdio>
#include <cstring>
#define DN 75005

char a[DN],b[DN],out[2*DN],sp[DN];
int pi[DN],n,m,pos;

void p() {
    for(int i=2,q=0; i<=n; ++i) {
        for(;a[i]!=a[q+1] && q!=0;q=pi[q]);
        if(a[i]==a[q+1]) ++q;
        pi[i]=q;
    }
}

int main()
{
    scanf("%s %s",a+1,b+1);
    n=strlen(a+1);m=strlen(b+1);
    p();
    for(int i=1,q=0; i<=m; ++i) {
        if(b[i]!=a[q+1]) {
            int qi=q;
            for(;b[i]!=a[q+1] && q>0; q=pi[q]);
            sp[i-q]=1;
        }
        if(b[i]!=a[q+1]) {
            printf("Yes");
            return 0;
        }
        if(b[i]==a[q+1]) ++q;
    }
    printf("No\n");
    for(int i=1; i<=m; ++i) {
        if(sp[i]) printf(" ");
        printf("%c",b[i]);
    }
    return 0;
}
