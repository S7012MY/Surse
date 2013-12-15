#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> vi;
char s[1000000];
int n;

int checksum(vi arr) {
    int result = 1;
    for(int i=0;i<arr.size(); ++i)
        result = (31 * result + arr[i]) % 1000003;
    return result;
}

int poz;

vi merge(vi &arr1,vi &arr2) {
    vi rez;
    int i,j;
    i=j=0;
    for(;i<arr1.size() && j<arr2.size();) {
        if('1'==s[poz]) {
            rez.push_back(arr1[i]);
            ++i;
        }else {
            rez.push_back(arr2[j]);
            ++j;
        }
        ++poz;
    }
    for(;i<arr1.size(); ++i) rez.push_back(arr1[i]);
    for(;j<arr2.size(); ++j) rez.push_back(arr2[j]);
    return rez;
}

vi merge_sort(vi &arr) {
    int n=arr.size();
    if(n<=1) return arr;
    int m=n/2;
    vi st,dr;
    for(int i=0; i<m; ++i) st.push_back(arr[i]);
    for(int i=m; i<n; ++i) dr.push_back(arr[i]);
    vi fh=merge_sort(st);
    vi sh=merge_sort(dr);
    return merge(fh,sh);
}

int main()
{
    int t;
    ifstream f("input");
    ofstream g("output");
    f>>t;
    for(int k=1;k<=t; ++k) {
        f>>n>>s;
        poz=0;
        vi act,rez;
        for(int i=0; i<n; ++i) act.push_back(i);
        vi cact=act;
        act=merge_sort(cact);
        for(int i=0; i<n; ++i) cout<<act[i]<<' ';
        cout<<'\n';
        rez.resize(n);
        for(int i=0; i<n; ++i) rez[act[i]]=i+1;
        g<<checksum(rez)<<'\n';
        g.flush();
    }
    return 0;
}
