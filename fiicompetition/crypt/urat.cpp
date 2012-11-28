#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s1,s2;
vector<pair<pair<int,int> , int>  >difs[55];

bool cmp(vector<pair<pair<int,int> , int>  > a,vector<pair<pair<int,int> , int>  > b) {
    return a.size()<b.size();
}

int main()
{
    ifstream f1("crypt.in");
    ifstream f2("crypt.out");
    ofstream g("rez.out");
    int n;
    f1>>n;
    f1.get();
    for(int i=1; i<=n; ++i) {
        getline(f1,s1);
        getline(f2,s2);
        int sum1=0,sum2=0;
        g<<s1<<" : ";
        for(int j=0; j<s1.size(); ++j) {
            g<<(int)s1[j]<<' ';
            sum1+=s1[j];
        }
        g<<'\n';
        s2.erase(s2.end()-1);
        g<<s2<<" : ";
        for(int j=0; j<s2.size(); ++j) {
            g<<(int)s2[j]<<' ';
            sum2+=s2[j];
        }
        g<<'\n';
        g<<"Diferenta: ";
        int fd=s1[0]-s2[0];
        for(int j=0; j<s1.size(); ++j) {
            g<<(int)s1[j]-s2[j]<<' ';
            difs[i].push_back(make_pair(make_pair(s1[j],s2[j]),s1[j]-s2[j]));
        }
        g<<'\n';
        g<<"Vdif: ";
        for(int j=0; j<s1.size(); ++j) g<<fd-s1[j]+s2[j]<<' ';
        /*g<<"Suma: ";
        for(int j=0; j<s1.size(); ++j) g<<(int)s1[j]+s2[j]<<' ';
        g<<'\n';
        g<<sum1<<' '<<sum2;
        g<<"Test: ";
        for(int j=1; j<s1.size(); ++j) g<<(int)s1[j]-s2[j-1]<<' ';*/
        g<<"\n\n";
    }
    /*sort(difs+1,difs+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        //for(int j=1; j<difs[i].size(); ++j) g<<difs[i][j].first.first-difs[i][j-1].first.first<<' ';
        //g<<'\n';
        for(int j=0; j<difs[i].size(); ++j) g<<difs[i][j].first.first<<' ';
        g<<'\n';
        //for(int j=1; j<difs[i].size(); ++j) g<<difs[i][j].first.second-difs[i][j-1].first.second<<' ';
        //g<<'\n';
        for(int j=0; j<difs[i].size(); ++j) g<<difs[i][j].first.second<<' ';
        g<<'\n';
        for(int j=0; j<difs[i].size(); ++j) g<<difs[i][j].second<<' ';
        if(i==n || difs[i].size()==difs[i+1].size()) g<<"\n\n";
        else g<<"\n\n\n\n\n\n";
    }*/
    return 0;
}
