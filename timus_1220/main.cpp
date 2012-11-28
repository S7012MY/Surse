#include <cstdio>

int st[100005],dc[1005],dm[1005];
char op[10];
int n;

int max(int a, int b) {
    if(a>b)return a;
    return b;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%s",op);
        if(op[1]=='U') {
            int a,b;
            scanf("%d %d",&a,&b);
            ++dc[a];
            dm[a]=max(dm[a],dc[a]);
        }else {
            int a;
            scanf("%d",&a);
            --dc[a];
        }
    }
    for(int i=0; i<=1000; ++i) {
        dc[i]=0;
        if(i) dm[i]+=dm[i-1];
    }
   // fflush(stdin);
    //fseek(stdin,0,SEEK_SET);
    rewind(stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%s",op);
        if(op[1]=='U') {
            int a,b;
            scanf("%d %d",&a,&b);
            ++dc[a];
            st[dm[a-1]+dc[a]]=b;
        }else {
            int a;
            scanf("%d",&a);
            printf("%d\n",st[dm[a-1]+dc[a]]);
            --dc[a];
        }
    }
    return 0;
}
