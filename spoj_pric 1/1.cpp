#include <cstdio>
#include <bitset>
#define lim 2147483648
#define mask 2147483647
#define nxt(i) (((i)+1234567890)&mask)
using namespace std;

char V[1<<29];

void c() {
	for (int i = 1; (i * i << 1) + (i << 1) <= lim; ++i) {
		if ((V[i >> 3] & (1 << (i & 7)))) continue ;
		for (int j = (i * i << 1) + (i << 1); (j << 1) + 1 <= lim; j += (i << 1) + 1)
			V[j >> 3] |= (1 << (j & 7)) ;
	}
}

inline bool prim (int i) {
    return ( V[i >> 3] & ( 1 << ( i & 7 ) ) ) == 0;
}

int main()
{
	c();
	int fs=1;
	for(int i=1;i<10;++i) {
	 	if(prim(fs)) printf("0");
		else printf("1");
		fs=nxt(fs);
	}
	return  0;
}
