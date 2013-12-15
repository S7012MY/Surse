#include <fstream>
using namespace std;
ifstream fin("kprime.in");
ofstream fout("kprime.out");

#define maxn 100005

int i,k1,k2,N,K;
int A[maxn],S[maxn];
long long NR;

int prim(int x)
{
	if(x==1) return 0;
	for(int d=2;d*d<=x;d++)
		if(x % d == 0) return 0;
	return 1;
}

int main()
{
	fin >> N >> K;
	for(i=1;i<=N;i++) fin >> A[i];
	
	for(S[0]=0,i=1;i<=N;i++) {
		S[i]=S[i-1];
		if(prim(A[i])) S[i]++;
	}
	
	for(i=1;i<=N;i++)
	{
		if(S[i]>S[i-1]) { // k1=min; k2=max;
			for(k1=k2;S[i]-S[k1+1]>K;k1++);
			if(S[i]-S[k1+1]==K && S[k1+1]>S[k1]) k1++;
			for(;S[i]-S[k2+1]>=K;k2++);
		}
		if(S[i]-S[k2]==K)
			NR=NR+k2-k1+1;
	}
	fout << NR;
}
