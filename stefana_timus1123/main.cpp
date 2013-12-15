#include <cstdio>
#include <cstring>

char a[2005];
int b[2005];
int main () {
    int n,i,x;
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;++i)b[i]=a[i]-'0';
    for(i=0;i<n/2;++i){
        if(b[i]>=b[n-i-1])b[n-i-1]=b[i];
        else {

            x=n-i-2;
            ++b[x];
            for(;b[x]>9;){
                b[x]=0;
                --x;
                ++b[x];
            }
             b[n-i-1]=b[i];
        }
    }

        for(i=0;i<n;++i)printf("%d",b[i]);


    return 0;
}
