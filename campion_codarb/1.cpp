#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cassert>
#define DL 10005
#define st fs
#define dr fd
using namespace std;

struct ab {
    char inf;
    ab *fs,*fd;
    ab() {
        fs=fd=NULL;
    }
} *t,*rn,*rn2;

ab *Arb(char*),*ArbSt(char*&),*ArbDr(char*&),*ArbSpec(char*&);

char sir[DL],arb[DL];
int lg,p;

void mrsd(ab *r) {
    int pi=p;
    r->inf=arb[p]+'A';
    if(arb[pi]&1) {
        r->fs=new ab;
        ++p;
        mrsd(r->fs);
    }
    if(arb[pi]%4>1) {
        r->fd=new ab;
        ++p;
        mrsd(r->fd);
    }
}

void msdr(ab *r) {
    int pi=p;
    r->inf=arb[p]+'A';
    if(arb[pi]%4>1) {
        r->fd=new ab;
        ++p;
        msdr(r->fd);
    }
    if(arb[pi]&1) {
        r->fs=new ab;
        ++p;
        msdr(r->fs);
    }
}

void rsd(ab *r) {
    printf("%c",r->inf);
    if(r->fs!=NULL) rsd(r->fs);
    if(r->fd!=NULL) rsd(r->fd);
}

void srd(ab *r) {
    if(r->fs!=NULL) srd(r->fs);
    printf("%c",r->inf);
    if(r->fd!=NULL) srd(r->fd);
}

void sdr(ab *r) {
    if(r->fs!=NULL) sdr(r->fs);
    if(r->fd!=NULL) sdr(r->fd);
    printf("%c",r->inf);
}

int main()
{
    freopen("codarb.in","r",stdin);
    freopen("codarb.out","w",stdout);
	//freopen("out.out","w",stderr);
    scanf("%s",sir);
    lg=strlen(sir);
    for(int i=3; i<lg; ++i) arb[i-3]=sir[i]-'A';
    lg=strlen(arb);
    t=new ab;
    if('R'==sir[0]) {
        mrsd(t);
    }else if('S'==sir[0]) {
        if('R'==sir[1]) {
			delete t;
            t=Arb(sir+3);
        }
        else {
            reverse(arb,arb+lg);
            msdr(t);
        }
    }
    printf("RSD");
    rsd(t);
    printf("\nSRD");
    srd(t);
    printf("\nSDR");
    sdr(t);
	printf("\n");
    return 0;
}

ab* Arb(char* pos) {
	//fprintf(stderr,"Arb %c\n",*pos);
	ab* sol = new ab();
	if (*pos == 'A') {
		sol->inf=*pos;
		++pos;
	} else if (*pos == 'C') {
		sol->inf=*pos;
		++pos;
        sol->dr = ArbDr(pos);
	} else {
        sol->st = ArbSt(pos);
        if (*pos == 'B') {
			sol->inf=*pos;
            ++pos;
        } else if (*pos == 'D') {
			sol->inf=*pos;
			++pos;
			sol->dr = ArbDr(pos);
		} else {
			fprintf(stderr,"EROARE Arb!!!");
			assert(0);
            // nu trebuie sa ajung niciodata aici!!!
            // eroare MARE!
            delete sol; // nu fac memory leak
			return NULL;
        }
	}
	return sol;
}

ab* ArbSpec(char* &pos) {
	ab *sol=new ab(),*pnt=new ab();
	if (*pos == 'H') {
		sol->inf=*pos;
		++pos;
		sol->dr=ArbDr(pos);
		++pos;
		pnt=ArbSpec(pos);
		if(pnt!=NULL) {
			pnt=ArbSpec(pos);
			pnt->fs=sol;
			return pnt;
		}//else --pos;
	} else if(*pos == 'F') {
		sol->inf=*pos;
		++pos;
		pnt=ArbSpec(pos);
		//fprintf(stderr,"%c ",pnt->inf);
		if(pnt!=NULL) {
			pnt=ArbSpec(pos);
			pnt->fs=sol;
			return pnt;
		}//else --pos;
	}else {
		delete sol; delete pnt;
		return NULL;
	}
	return sol;
}
 
ab* ArbSt(char* &pos) {
	//fprintf(stderr,"ArbSt %c\n",pos);
    ab* sol = new ab(),*pnt=new ab();
    if (*pos == 'E') {
		sol->inf=*pos;
        ++pos;
		pnt=ArbSpec(pos);
		//fprintf(stderr,"%c ",pnt->inf);
		if(pnt!=NULL) {
			pnt->fs=sol;
			return pnt;
		}//else --pos;
    } else if (*pos == 'G') {
		sol->inf=*pos;
        ++pos;
        sol->dr = ArbDr(pos);
		++pos;
		pnt=ArbSpec(pos);
		if(pnt!=NULL) {
			pnt->fs=sol;
			return pnt;
		}//else --pos;
	} else {
		// nu trebuie sa ajung niciodata aici!!!
		// eroare MARE!
		fprintf(stderr,"EROARE ArbSt %c!!!");
		assert(0);
		delete sol; // nu fac memory leak
		return NULL;
	}
	return sol;
}
 
ab* ArbDr(char* &pos) {
	//fprintf(stderr,"ArbDr %c\n",pos);
    ab* sol = new ab();
    if (*pos == 'I') {
		sol->inf=*pos;
        ++pos;
	} else if (*pos == 'K') {
		sol->inf=*pos;
        ++pos;
		sol->dr = ArbDr(pos);
    } else {
        sol->st = ArbSt(pos);
        if (*pos == 'J') {
			sol->inf=*pos;
            ++pos;
		} else if (*pos == 'L') {
			sol->inf=*pos;
            ++pos;
            sol->dr = ArbDr(pos);
		} else {
			assert(0);
            // nu trebuie sa ajung niciodata aici!!!
            // eroare MARE!
			fprintf(stderr,"EROARE ArbDr!!!");
            delete sol; // nu fac memory leak
            return NULL;
        }
    }
	return sol;
}
