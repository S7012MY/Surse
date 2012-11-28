#include <cstdio>
#include <cstring>

char ore[5],rezm[10],rezM[10],dif[10],orei[5];

void swap(char &a,char &b) {
    char aux=a;
    a=b;
    b=aux;
}

void makeDif() {
    dif[4]=rezM[4]-rezm[4]+'0';
    char tr=0;
    if(dif[4]<'0') dif[4]+=10,tr=-1;
    dif[3]=rezM[3]-rezm[3]+'0'+tr;
    tr=0;

    if(dif[3]<'0') dif[3]+=6,tr=-1;
    dif[1]=rezM[1]-rezm[1]+'0'+tr;
    tr=0;

    if(dif[1]<'0') dif[1]+=10,tr=-1;
    dif[0]=rezM[0]-rezm[0]+'0'+tr;
}

int main()
{
    freopen("ore.in","r",stdin);
    freopen("ore.out","w",stdout);
    for(int i=0; i<=2359; ++i) {
        int beg=0;
        memset(ore,0,sizeof(ore));
        if(i<1000) ++beg;
        if(i<100) ++beg;
        if(i<10) ++beg;
        for(int i=0; i<beg; ++i) ore[i]='0';

        sprintf(ore+beg,"%d",i);
        memcpy(orei,ore,sizeof(ore));
        //printf("%s\n",ore);
        //scanf("%s",ore);
        for(int i=0; i<4; ++i) for(int j=i+1; j<4; ++j) if(ore[i]>ore[j]) swap(ore[i],ore[j]);//sortez crescator
        //ora minima
        rezm[0]=ore[0];
        rezm[1]=ore[1];
        rezm[2]=rezM[2]=dif[2]=':';
        rezm[3]=ore[2];
        rezm[4]=ore[3];
        if(rezm[3]>'6') swap(rezm[3],rezm[1]);

        //ora maxima
        int fp=3;//prima pozitie pe care am cifra valida pentru pozitia pe care o completez
        if(ore[3]>'2') --fp;
        if(ore[2]>'2') --fp;
        if(ore[1]>'2') --fp;
        rezM[0]=ore[fp];
        ore[fp]=ore[3];
        fp=2;
        if(ore[2]>'3') --fp;
        if(ore[1]>'3') --fp;
        rezM[1]=ore[fp];
        ore[fp]=ore[2];

        fp=1;
        if(ore[1]>'6')--fp;
        rezM[3]=ore[fp];
        ore[fp]=ore[1];
        rezM[4]=ore[0];

        makeDif();
        printf("Test %d: %s\nRezultat:\n%s\n%s\n%s\n\n",i,orei,rezm,rezM,dif);
    }
    return 0;
}
