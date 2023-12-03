#include <bits/stdc++.h>
using namespace std;
#define N 100
int dscanh[N][N];
int n,m,s,t;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m>>s>>t;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    dscanh[u][v]+=w;
}
int res=0;

while(1){

    vector<bool> danhdau(n+1, false);
    vector<int> duongdi(n+1, 0);
    queue<int> qu;
    qu.push(s);
    danhdau[s]=true;
    while(!qu.empty()){

        int tmp= qu.front();
        qu.pop();
        for(auto i= 1; i <= n; i++){
            if(!danhdau[i]&&dscanh[tmp][i]>0){
                danhdau[i]=true;
                duongdi[i]=tmp;
                qu.push(i);
            }
        }

    }
    if(!danhdau[t])break;
                int luong=99999999;
                int temp=t;
                while(temp!=s){
                    int tmp=duongdi[temp];
                luong=min(luong,dscanh[tmp][temp]);
                temp=tmp;
                }
                temp=t;
                while(temp!=s){
                    int tmp=duongdi[temp];

                dscanh[tmp][temp]-=luong;
                dscanh[temp][tmp]+=luong;
                temp=tmp;
                }
                res+=luong;
}
cout<<res;
}
