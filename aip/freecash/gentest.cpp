#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define DN 1000
using namespace std;

int n,rez,c=1;
pair<int,int> p[100005];

int main()
{
    srand(time(NULL));
    for(int t=1; t<101; ++t) {
        char in[55],ou[55];
        sprintf(in,"grader_test%d.in",t);
        sprintf(ou,"grader_test%d.ok",t);
        ofstream f(in); ofstream g(ou);

        n=rand()%100000+1;
        rez=0,c=1;
        f<<n<<'\n';
        for(int i=1; i<=n; ++i) {
            p[i].first=rand()%24; p[i].second=rand()%60;
        }
        sort(p+1,p+n+1);
        for(int i=1; i<=n; ++i) f<<p[i].first<<' '<<p[i].second<<'\n';
        for(int i=2; i<=n; ++i) {
            if(p[i].first==p[i-1].first && p[i].second==p[i-1].second) ++c;
            else {
                rez=max(rez,c);
                c=1;
            }
        }
        rez=max(rez,c);
        g<<rez;
    }
    return 0;
}
