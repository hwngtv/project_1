#include <bits/stdc++.h>
using namespace std;

int sodinh, socanh;
vector<int> dscanh[1000];
bool danhdau[1000];

void input() {
    cin >> sodinh >> socanh;
    int dinh1, dinh2;
    for(int i = 1; i <= socanh; i++) {
        cin >> dinh1 >> dinh2;
        dscanh[dinh2].push_back(dinh1);
        dscanh[dinh1].push_back(dinh2);
    }
    for(int i = 1; i <= sodinh; i++) {
        sort(dscanh[i].begin(), dscanh[i].end());
    }
}

void dfs(int k) {
    cout<<k<<" ";
    danhdau[k]=true;
    for(int i:dscanh[k])
        if(!danhdau[i])dfs(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    for(int i=1;i<=sodinh;i++)if(!danhdau[i])dfs(i);
    return 0;
}
