#include <bits/stdc++.h>
using namespace std;
int T,a[1000][1000]={},bacdinh[1000],sodinh,socanh;
void input(){
    cin >>T;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    while(T--){
        cin>>sodinh>>socanh;
        int u,v;
        for(int i=1;i<=socanh;i++){
            cin>>u>>v;
            a[u][v]++;
            a[v][u]++;
            bacdinh[u]++;
            bacdinh[v]++;
        }int te=1;
        for(int i=1;i<=sodinh;i++){
            if(bacdinh[i]>=sodinh/2)continue;
            else {te=0;
                cout<<0<<"\n";
                break;
            }
        }
        if(te==1)cout<<1<<"\n";
    }
    return 0;
}
