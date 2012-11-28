#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s1,s2;
vector<pair<pair<int,int> , int>  >difs[55];
vector<int> v[2006];

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
        for(int i=0; i<s1.size(); ++i) v[(int)s1[i]+200].push_back((int)s2[i]);
    }
    for(int i=0; i<500; ++i) if(v[i].size()) {
        g<<(char)(i-200)<<'\n';
        for(int j=0; j<v[i].size(); ++j) g<<v[i][j]<<' ';
        g<<'\n';
    }
    return 0;
}
