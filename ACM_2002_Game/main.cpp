#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int pa,pb,k,l;
double prob[1005][1005][2],psa,psb;

double fa() {
    for(int A=0;A<=l;++A) for(int B=0;B<=l;++B) {
        if(A && B<l) prob[A][B][0]=prob[A-1][B][0]*pa/100.0+prob[A-1][B][1]*(100.0-pb)/100.0;
        if(B && A<l) prob[A][B][1]=prob[A][B-1][1]*pb/100.0+prob[A][B-1][0]*(100.0-pa)/100.0;
    }
    double ret=0;
    for(int i=0; i<l; ++i) ret+=prob[l][i][0];
    return ret;
}

int main()
{
    int t;
    for(cin>>t;t;--t) {
        cin>>pa>>pb>>k>>l;
        memset(prob,0,sizeof(prob));
        prob[0][0][0]=1;
        psa=fa();
        prob[0][0][0]=0;
        prob[0][0][1]=1;
        psb=fa();
        memset(prob,0,sizeof(prob));
        prob[0][0][0]=prob[0][0][1]=0.5;
        for(int a=0; a<=k; ++a) for(int b=0; b<=k; ++b) {
            if(a && b<k) {
                prob[a][b][0]=prob[a-1][b][1]*psb;
                prob[a][b][1]=prob[a-1][b][0]*psa;
            }
            if(b && a<k) {
                prob[a][b][0]+=(prob[a][b-1][1]*(1.0-psb));
                prob[a][b][1]+=(prob[a][b-1][0]*(1.0-psa));
            }
        }
        double rez=0;
        for(int i=0; i<k; ++i) {
            rez+=prob[k][i][0];
            rez+=prob[k][i][1];
        }
        cout<<fixed<<setprecision(1)<<rez*100.0<<'\n';
        //for(double i=0; i<=1000000; i+=0.001);
    }
    return 0;
}
