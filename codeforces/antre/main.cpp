#include <iostream>
#include <cstdio>
#include <string>
#include <bitset>
#define DN 10005
using namespace std;

string s[10005][15],inp;
int n,m;
bitset<DN> match[15][DN];

int main()
{
    freopen("database.in","r",stdin);
    freopen("database.out","w",stdout);
    cin>>n>>m;
    cin.get();
    for(int i=0; i<n; ++i) {
        getline(cin,inp);
        int ic=-1;
        string c;
        for(int j=0; j<inp.size(); ++j)
            if(','==inp[j]) {
                s[i][++ic]=c;
                c.clear();
            }else c+=inp[j];
        s[i][++ic]=c;
    }
    /*for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) cout<<s[i][j]<<'|';
        cout<<'\n';
    }*/
    for(int i1=0; i1<n; ++i1) for(int i2=i1+1; i2<n; ++i2) for(int c=0; c<m; ++c)
        if(s[i1][c].compare(s[i2][c])==0) match[c][i1][i2]=1;
    for(int i1=0; i1<n; ++i1) for(int i2=i1+1; i2<n; ++i2)
        for(int c=0; c<m; ++c) if(match[c][i1][i2])
            for(int c2=c+1; c2<m; ++c2) if(match[c][i1][i2]) {
                cout<<"NO\n"<<i1+1<<' '<<i2+1<<'\n'<<c+1<<' '<<c2+1<<'\n';
                return 0;
            }
    cout<<"YES";
    return 0;
}
