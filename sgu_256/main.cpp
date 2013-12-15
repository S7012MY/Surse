#include<iostream>
#include<algorithm>
#define x first
#define y second
#define DS 1005
using namespace std;

typedef pair<int,int> per;

per a[20];
int d[DS][5][5][5][5][5];//cate baloane am umflat in starea ds si fiecare umflator ii in starea coresp
int v[10],w[10],i,j,n,m,s;

bool cmp(per a,per b) {
    if(a.x==b.x) return a.y<b.y;
    return a.x>b.x;
}

int main()
{
    cin>>m>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
        if (a[i].x>=m) {
            cout<<1;
            return 0;
        }
    }
    sort(a+1,a+n+1,cmp);
    n=5;
    d[1][a[1].y][0][0][0][0]=a[1].x;
    d[1][0][a[2].y][0][0][0]=a[2].x;
    d[1][0][0][a[3].y][0][0]=a[3].x;
    d[1][0][0][0][a[4].y][0]=a[4].x;
    d[1][0][0][0][0][a[5].y]=a[5].x;
    for(i=1;i<=10*m;i++) {
        for(v[1]=0;v[1]<=a[1].y;++v[1]) for(v[2]=0;v[2]<=a[2].y;++v[2]) for(v[3]=0;v[3]<=a[3].y;++v[3])
            for(v[4]=0;v[4]<=a[4].y;++v[4]) for(v[5]=0;v[5]<=a[5].y;++v[5]) {
                s=d[i][v[1]][v[2]][v[3]][v[4]][v[5]];
                for(j=1;j<=n;++j) w[j]=max(v[j]-1,0);
                for(j=1;j<=n;++j) if(v[j]==0) {
                    w[j]=a[j].y;
                    d[i+1][w[1]][w[2]][w[3]][w[4]][w[5]]=max(d[i+1][w[1]][w[2]][w[3]][w[4]][w[5]],s+a[j].x);
                    if(s+a[j].x>=m) {
                        cout<<i+1;
                        return 0;
                    }
                    w[j]=0;
                }
                d[i+1][w[1]][w[2]][w[3]][w[4]][w[5]]=max(d[i+1][w[1]][w[2]][w[3]][w[4]][w[5]],s);
            }
    }
    return 0;
}
