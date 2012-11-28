#include <fstream>
#define DN 1000005
using namespace std;

int n,N,k,ssol,pt,rez,bst,p[DN],c[DN],a[DN]={0x80000000};

void upheap(int k) {
	int val=a[k];
	while (a[k/2]>=val) {
		a[k]=a[k/2];
		k/=2;
	}
	a[k]=val;
}


void downheap(int k) {
	int j, val=a[k];
	while(k+k<=N) {
		j=k+k;
		if(j<N)
			if(a[j]>a[j+1])
				j++;
		if(val<=a[j]) break;
		a[k]=a[j];
		k=j;
	}
	a[k]=val;
}

void insert (int val) {
	N++;
	a[N]=val;
	upheap(N);
}

int rem() {
	int val=a[1];
	a[1]=a[N];
	N--;
	downheap(1);
	return val;
}

int main()
{
    ifstream f("ephie.in");
    ofstream g("ephie.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) f>>p[i]>>c[i];
    for(int i=1; i<=k; ++i) {
        pt+=p[i];
        insert(p[i]+c[i]);
    }
    rez=pt;
    for(int i=k+1; i<=n; ++i) {
        pt+=p[i];
        insert(p[i]+c[i]);
        ssol+=rem();
        bst=pt-ssol;
        rez=max(rez,bst);
    }
    g<<rez;
    return 0;
}
