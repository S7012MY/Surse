#include <cstdio>
#include <bitset>
using namespace std;
long long prime[1000005];
bitset <1000005>a;
int prim(long long n){
 for(int i=1;prime[i]*prime[i]<=n;++i){
  if(n%prime[i]==0)return 0;
  
 }
 return 1;
}
int main () {
 int n,c=0;
 long long i,j,dim=0,x=0,uv=0,p=1,cc;
 freopen("numere.in","r",stdin);
 freopen("numere.out","w",stdout);
 scanf("%d",&n);
 for(i=2;i<=1000;++i){
  if(a[i]==0){
   for(j=i*i;j<=1000000;j+=i){
    a[j]=1;
   }
  }
 }
 for(i=2;i<=1000000;++i){
  if(a[i]==0){
   
   prime[++dim]=i;
  }
 }
 
 
 for(i=1;i<=dim&&c!=n;i+=2LL){
  p=1;
  cc=prime[i+1LL];
  for(;cc;){
   cc=cc/10;
   p=p*10;
  }
  
  x=prime[i]*p+prime[i+1LL];
  if(prim(x)){
   ++c;
   uv=x;
  }
 }
 printf("%lld\n",uv);

 return 0;
}
