#include <iostream>
#include <string>
using namespace std;

int n1,c1,n2,t,c2,n3;

int main()
{
    cin>>n1>>c1>>n2>>t>>c2>>n3;
    int k,m=0,cs,cm;
    cin>>k;
    string d;
    for(int i=1; i<=k; ++i) {
        cin>>d;
        cm=(d[0]-'0')*10+d[1]-'0';
        m+=cm;
        cs=(d[3]-'0')*10+d[4]-'0';
        if(cs>6 || (cm && cs!=0)) ++m;
    }
    //cout<<m<<'\n';
    cout<<"Basic:     "<<n1+c1*m<<'\n';
    cout<<"Combined:  "<<n2+c2*((m>t)?(m-t):0)<<'\n';
    cout<<"Unlimited: "<<n3;
    return 0;
}
