#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#define NO 2005
#define x first
#define y second
#define PI 3.1415926535897932384626433832795028841971693993751058209749
using namespace std;

typedef pair<int, int> per;
int n,fol[NO],sol[NO],sz;
per pct[NO];

double pnt(per a,per b) {
    return(a.x-b.x) / (a.y-b.y);
}

double u(per a,per b, per c) {
    double u1=atan2((double)b.x-a.x,b.y-a.y),u2=atan2((double)b.x-c.x,b.y-c.y);
    double u12=min(fabs(u1-u2),2*PI-fabs(u1-u2));
    return u12;
}

void bk(int r1,int r2) {
	//cout<<r1<<' '<<r2<<' '<<sz<<'\n';
    if(sz>=n) {
        cout<<"YES\n";
        for(int i=1; i<=sz; ++i) cout<<sol[i]+1<<' ';
        exit(0);
    }
    vector<int> mv;
    for(int i=0; i<n; ++i) if(!fol[i]) mv.push_back(i);
    random_shuffle(mv.begin(),mv.end());
    int r3;
    for(int i=0; i<mv.size(); ++i) if(u(pct[r1],pct[r2],pct[mv[i]])<PI/2-1e-8 || u(pct[r1],pct[r2],pct[mv[i]])>(3*PI)/2+1e-8) {
        r3=mv[i];
        fol[r3]=1;
        sol[++sz]=r3;
        bk(r2,r3);
        --sz;
        fol[r3]=0;
    }
}

int main()
{
    srand(time(NULL));
    cin>>n;
    n+=2;
    for(int i=0; i<n; ++i)cin>>pct[i].x>>pct[i].y;
    for(;;) {
        int r1=rand()%n,r2=rand()%n;
        if(r1==r2) continue;
        fol[r1]=fol[r2]=1;
        sol[++sz]=r1; sol[++sz]=r2;
        bk(r1,r2);
        fol[r1]=fol[r2]=sz=0;
    }
    return 0;
}
