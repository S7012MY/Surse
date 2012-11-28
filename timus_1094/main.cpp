#include <cstdio>
#include <cctype>
#include <cstring>

char c,r[80];

int main() {
        int p=0;
        for(;scanf("%c",&c)!=-1;) {
                if(c=='<') p=(p+79)%80;
                else if(c=='>') p=(p+1)%80;
                else if(!(c == '\n' || c == '\r')) r[p]=c,p=(p+1)%80;
                //printf("%c",c);
                //printf("%d",p);
        }
        printf("%s",r);
        return 0;
}
