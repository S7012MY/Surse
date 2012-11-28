#include <cstdio>

char tbl[28][28];
int lin[28],col[28],d1[27],d2[27];//atacate
int rezx[28],rezy[28],sz;//rezultat
int rx[28],ry[28],szf=99;//rezultat final

bool at(int i, int j) {
	if('0'==tbl[i][j] &&
		!lin[i] && !col[j] &&
		!d1[i+j] && !d2[i-j+8]) return 0;
	return 1;
}

bool pesteTot() {
	for(int i=0; i<8; ++i) for(int j=0; j<8; ++j)
		if(!at(i,j) && '0'==tbl[i][j]) return 0;
	return 1;
}

void pune(int i, int j) {
	if(j>7) {
	    pune(i+1,0);
	    return;
	}
	if(i>7) return;
	if(at(i,j)) pune(i,j+1);
	else {
		++lin[i]; ++col[j]; ++d1[i+j]; ++d2[i-j+8];
		rezx[++sz]=i;
		rezy[sz]=j;
		if(pesteTot() && sz<szf) {
			szf=sz;
			for(int i=1; i<=sz; ++i) {
				rx[i]=rezx[i];
				ry[i]=rezy[i];
			}
		}
		pune(i,j+1);
		--lin[i]; --col[j]; --d1[i+j]; --d2[i-j+8];
		--sz;
		pune(i,j+1);
	}
}

int main() {
	freopen("dame2.in","r",stdin);
	freopen("dame2.out","w",stdout);
	for(int i=0; i<8; ++i)
		scanf("%s\n",tbl[i]);
	pune(0,0);
    printf("%d\n",szf);
    for(int i=1; i<=szf; ++i)
        printf("%d %d ",rx[i]+1,ry[i]+1);
	return 0;
}
