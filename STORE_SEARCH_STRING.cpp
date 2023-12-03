#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<string> se;
    string s,q;
    while(1){
        cin>>s;
        if(s=="*")break;
        se.insert(s);
    }
    while(1){
        cin>>q;
        if(q=="find"){
            cin>>s;
            if(se.find(s)==se.end())cout<<0<<"\n";
            else cout<<1<<"\n";
        }
        else if(q=="insert"){
            cin>>s;
            if(se.find(s)==se.end()){
                    cout<<1<<"\n";
                    se.insert(s);
            }
            else cout<<0<<"\n";
        }
        else break;
    }
    return 0;
}
