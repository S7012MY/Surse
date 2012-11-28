#include <iostream>
#include <set>
#define DN 100005
using namespace std;

int n,K,v[55],af,st;
set<int> s;

int main()
{
    cin>>n>>K;
    for(int i=1; i<=n; ++i) {
        cin>>v[i];
        st+=v[i];
        if(af<K) {
            cout<<1<<' '<<v[i]<<'\n';
            ++af;
            s.insert(v[i]);
        }
    }
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(s.find(v[i]+v[j])==s.end() && af<K){
        ++af;
        cout<<"2 "<<v[i]<<' '<<v[j]<<'\n';
        s.insert(v[i]+v[j]);
    }
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
        for(int k=j+1; k<=n; ++k) if(s.find(v[i]+v[j]+v[k])==s.end() && af<K){
            ++af;
            cout<<"3 "<<v[i]<<' '<<v[j]<<' '<<v[k]<<'\n';
            s.insert(v[i]+v[j]+v[k]);
        }
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
        for(int k=j+1; k<=n; ++k)
            for(int l=k+1; l<=n; ++l) if(s.find(v[i]+v[j]+v[k]+v[l])==s.end() && af<K){
            ++af;
            cout<<"4 "<<v[i]<<' '<<v[j]<<' '<<v[k]<<' '<<v[l]<<'\n';
            s.insert(v[i]+v[j]+v[k]+v[l]);
        }

    for(int i=1; i<=n; ++i) if(af<K && s.find(st-v[i])==s.end()) {
        ++af;
        cout<<n-1<<' ';
        for(int j=1; j<=n; ++j) if(j!=i) cout<<v[j]<<' ';
        cout<<'\n';
        s.insert(st-v[i]);
    }
    for(int i=1; i<=n; ++i) for(int k=i+1; k<=n; ++k) if(af<K && s.find(st-v[i]-v[k])==s.end()) {
        cout<<n-2<<' ';
        ++af;
        for(int j=1; j<=n; ++j) if(j!=i && j!=k) cout<<v[j]<<' ';
        cout<<'\n';
        s.insert(st-v[i]-v[k]);
    }
    for(int i=1; i<=n; ++i) for(int k=i+1; k<=n; ++k) for(int l=k+1; l<=n; ++l)
        if(af<K && s.find(st-v[i]-v[k]-v[l])==s.end()) {
            ++af;
            cout<<n-2<<' ';
            for(int j=1; j<=n; ++j) if(j!=i && j!=k && j!=l) cout<<v[j]<<' ';
            cout<<'\n';
            s.insert(st-v[i]-v[k]-v[l]);
        }
    return 0;
}
