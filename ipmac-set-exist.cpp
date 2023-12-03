#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>t;
        if(s.find(t)!=s.end())cout<<1<<endl;
        else {
            cout<<0<<endl;
            s.insert(t);
        }
    }

    return 0;
}
