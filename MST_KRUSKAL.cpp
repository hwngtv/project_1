#include <bits/stdc++.h>
using namespace std;
#define N 100009
int cha[N], hang[N];
struct canh{
    int dinh1,dinh2,trongso;
};
int sodinh,socanh;
vector<canh>dscanh;
bool sosanh(const canh &a,const canh &b){
    return a.trongso<b.trongso;
}
int tim(int dinh){
    if(cha[dinh]!=dinh)cha[dinh]=tim(cha[dinh]);
    return cha[dinh];
}
bool nhap(int u,int v){
    u=tim(u);v=tim(v);
    if(u==v)return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}
void input(){
    cin>>sodinh>>socanh;
    for(int i=1;i<=socanh;i++){
        canh temp;
        cin>>temp.dinh1;
        cin>>temp.dinh2;
        cin>>temp.trongso;
        dscanh.push_back(temp);
    }
    sort(dscanh.begin(),dscanh.end(),sosanh);
}

int res=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    for (int i=1; i<=sodinh; i++) {
        cha[i] = i;
        hang[i] = 0;
    }
    for(canh e:dscanh){
        if(nhap(e.dinh1,e.dinh2))res+=e.trongso;
    }
    cout<<res;
    return 0;
}
