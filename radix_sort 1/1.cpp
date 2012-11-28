#include <iostream>
#include <fstream>
#define DN 500005
using namespace std;

int N, A[DN], B[DN];

void merge_sort(int l, int r)
{
    int m = (l + r) >> 1, i, j, k;
    if (l == r) return;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    for (i=l, j=m+1, k=l; i<=m || j<=r; )
        if (j > r || (i <= m && A[i] < A[j]))
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    for (k = l; k <= r; k++) A[k] = B[k];
}

int main(){
	ifstream f("algsort.in");
	ofstream g("algsort.out");
	f>>N;
	for(int i=1; i<=N; ++i) f>>A[i];
	merge_sort(1,N);
	for(int i=1; i<=N; ++i) g<<A[i]<<' ';
	//for(int i=1; i<=N; ++i) cout<<A[i]<<' ';
	return 0;
	
}