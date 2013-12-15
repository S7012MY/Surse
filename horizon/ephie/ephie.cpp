#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define BM 1000005
int s[BM],np[BM],bst[BM];
priority_queue <int,vector<int>,greater<int> >heap;
int main () {
        int n,k,i,ss=0;
        freopen("ephie.in","r",stdin);
        freopen("ephie.out","w",stdout);
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;++i)scanf("%d %d",&s[i],&np[i]);
        for(i=1;i<=k;++i){
                heap.push(s[i]+np[i]);
                bst[i]=bst[i-1]+s[i];
        }
        for(i=k+1;i<=n;++i){
                if(s[i]-heap.top()-ss>0){// daca varful + suma neplacerilor discurilor scoase fara a fi bagate vreodata in heap e mai mica decat s[i], bag in heap
                        bst[i]=bst[i-1]+s[i]-heap.top()-ss;// din bst[i-1] scad varful si suma neplacerilor discurilor scoase fara sa intre vreodata in heap
                        heap.pop();// scot varful
                        heap.push(s[i]+np[i]);//adaug noul disc in heap
                        ss=0;//am scazut suma neplacerilor discurilor care au fost scoase, asa ca o fac 0
                }
                else {// asta inseamna ca discul nu merita ascultat
                        bst[i]=bst[i-1];//maximul e acelasi
                        ss+=np[i];//la suma neplacerilor se adauga neplacerea cauzata de discul curent (pt ca nu merita sa il ascult)
                }
 
        }
        printf("%d",bst[n]);
        return 0;
}
 
