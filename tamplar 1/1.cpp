#include <fstream>
#define DN 10000005
using namespace std;

int n,a[DN];

void inmul(int a[DN], int x){
    int rest = 0;
    int i;
    for(i=1; i<=a[0]||rest; i++,rest=rest/10000){
        a[i] = (rest+=a[i]*x) % 10000;
    }
    a[0] = i-1;
}


int main() 
{
	freopen("tamplar.in","r",stdin);
	freopen("tamplar.out","w",stdout);
	scanf("%d",&n);
	a[0]=a[1]=1;
	for(int i=2; i<n; ++i) inmul(a,i);
	printf("%d", a[a[0]]);
    for(int i=a[0]-1; i; i--){
        printf("%04d", a[i]);
    }
	return 0;
}