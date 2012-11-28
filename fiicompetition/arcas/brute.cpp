#include <cstdio>
int arcasi[2][100005];
int ord[200005];
int tinta(int n,int el){
        int i;
        for(i=1;i<=n;++i)if(arcasi[0][i]==el||arcasi[1][i]==el)return i;
}
int main (){
        int n,tu,r,i,poz,ok=0,j,t,aux,tintaf,tintac,pozf,pif;
	freopen("arcas.in","r",stdin);
	freopen("arcas.out","r",stdout);
        scanf("%d %d",&n,&r);
        tintaf=n;
        scanf("%d",&tu);
        for(i=1;i<=2*n-1;++i)scanf("%d",&ord[i]);
        for(poz=1;poz<=2*n;++poz){
                //printf("pt inceput din %d\n",poz);
                ok=0;
                for(i=1;i<=2*n;++i){
                        if(i==poz){
                                arcasi[(i+1)%2][(i+1)/2]=tu;
                                ok=1;
                        }
                        else {
                                if(ok==0)arcasi[(i+1)%2][(i+1)/2]=ord[i];
                                else arcasi[(i+1)%2][(i+1)/2]=ord[i-1];
                        }
                }
                
                for(i=1;i<=2*n+r%n;++i){
                        if(arcasi[0][1]<arcasi[1][1])t=arcasi[1][1];
                        else t=arcasi[0][1];
                        for(j=n;j>1;--j){
                                if(arcasi[0][j]<arcasi[1][j]){
                                        aux=arcasi[0][j];
                                        arcasi[0][j]=t;
                                        t=aux;
                                }
                                else{
                                        aux=arcasi[1][j];
                                        arcasi[1][j]=t;
                                        t=aux;
                                }
                        }
                        if(arcasi[0][1]<arcasi[1][1])arcasi[1][1]=t;
                        else arcasi[0][1]=t;
                        //printf("dupa runda %d\n",i);
                        //for(int k=1;k<=n;++k)printf("%d %d\n",arcasi[0][k],arcasi[1][k]);
                        
                }
                tintac=tinta(n,tu);
                if(tintac<=tintaf){
                        pozf=poz;
                        tintaf=tintac;
                }
        }
	int rez;
	fscanf(stdout,"%d",&rez);
	if(rez!=(pozf+1)/2) {
		fprintf(stderr,"GRESIT! %d %d",(pozf+1)/2,tintaf);
		while(1);
	}else fprintf(stderr,"corect\n");
        //printf("%d",(pozf+1)/2);
        return 0;
}
