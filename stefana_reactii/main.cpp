#include <cstdio>
#include <stack>
using namespace std;
int s[15005];
stack <pair<int, int> >st;
inline int minim(int a,int b){
    if(a<b)return a;
    return b;
}
inline int maxim(int a,int b){
    if(a>b)return a;
    return b;
}
inline int f(pair<int, int>&el,pair<int,int>a){
    if(el.first==a.second+1||el.second==a.first-1){
        el.first=minim(el.first,a.first);
        el.second=maxim(a.second,el.second);
        return 1;
    }
    return 0;
}
int main () {
    int n,m,i,j;
    freopen("reactii.in","r",stdin);
    freopen("reactii.out","w",stdout);
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",&s[j]);
         }
         for(j=1;j<=m;++j){
             pair<int,int>el=make_pair(s[j],s[j]);
             for(;st.size()&&f(el,st.top());st.pop());
             st.push(el);
         }
         if(st.size()==1)printf("1\n");
         else printf("0\n");
         for(;st.size();st.pop());
    }
    return 0;
}
